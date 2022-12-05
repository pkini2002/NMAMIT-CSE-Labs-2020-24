Consider the following database of student enrollment in courses & books adopted for each course:

STUDENT (regno: string, name: string, major: string, bdate: date)
COURSE (course #: int, cname: string, dept: string)
ENROLL (regno: string, course#: int, sem: int marks: int)
BOOK _ ADOPTION (course#: int, sem: int, book-ISBN: int)
TEXT (book-ISBN: int, book-title: string, publisher: string, author: string)

1.	Produce a list of text books (include Course #, Book-ISBN,Book-title) 
	in the alphabetical order for courses offered by th ‘CS’ 
	department that use more than two books.
2.	List any department that has all its adopted books 
	published by a specific publisher.
3.	List the bookISBNs and book titles of the department that 
	has maximum number of students


create database student

use student

create table STUDENT (
			regno varchar(10),
			fname char(15),
			major char (20),
			bdate datetime
			primary key(regno)
)

insert into STUDENT values ('111','ravi','academic','1989-11-09')
insert into STUDENT values ('112','sudha','academic','1979-07-04')
insert into STUDENT values ('113','kumar','academic','1979-01-06')
insert into STUDENT values ('114','raju','academic','1999-10-02')
insert into STUDENT values ('115','hemanth','academic','1988-11-04')

select * from student

create table COURSE 
(
		course int,
		cname varchar(15),
		dept  char (20),
		primary key(course)
)

insert into COURSE values (1,'DBMS','CS')
insert into COURSE values (2,'COMPILER','CS')
insert into COURSE values (3,'JAVA','CS')
insert into COURSE values (4,'SIG PROCESSING','ENC')
insert into COURSE values (5,'DIGTAL CIRCUITS','ENC')
insert into COURSE values (6,'MACHINE DESIGN','MECH')
insert into COURSE values (7,'THEMODYNAICS','MECH')
insert into COURSE values (8,'AUTOCAD','MECH')


select * from COURSE


create table TEXTBOOK (
			bookISBN int,
			title varchar(50),
			publisher  varchar(20),
			author  char(20),
			primary key (bookISBN)
)

insert into TEXTBOOK  values (201,'Fundamentals of DBMS','McGraw','NAVATHE')
insert into TEXTBOOK  values (202,'Database Design','McGraw','Raghu Rama')
insert into TEXTBOOK  values (203,'Compiler design','Pearson','Ulman')
insert into TEXTBOOK  values (204,'JAVA complete Reference','McGraw','BALAGURU')
insert into TEXTBOOK  values (205,'Singals and Fundumentals','McGraw','NITHIN')
insert into TEXTBOOK  values (206,'Machine Theory','McGraw','Ragavan')
insert into TEXTBOOK  values (208,'Circuit design','McGraw','Rajkamal')
insert into TEXTBOOK  values (207,'Thermodynamics','McGraw','Alfred')
insert into TEXTBOOK  values (209,'Electronic Circuits','McGraw','Alfred')
insert into TEXTBOOK  values (210,'Circuits Theory','McGraw','Alfred')

select * from TEXTBOOK

create table BOOKADAPTION (
			course int,
			sem int,
			bookISBN int,
			primary key(course, sem,bookISBN),
			foreign key(course) references COURSE(course) on delete cascade on update cascade,
			foreign key(bookISBN) references TEXTBOOK (bookISBN) on delete cascade on update cascade,
)

insert into BOOKADAPTION  values (1,5,201)
insert into BOOKADAPTION  values (1,7,202)
insert into BOOKADAPTION  values (2,5,203)
insert into BOOKADAPTION  values (2,6,203)
insert into BOOKADAPTION  values (3,7,204)
insert into BOOKADAPTION  values (4,3,205)
insert into BOOKADAPTION  values (4,5,209)
insert into BOOKADAPTION  values (5,5,205)
insert into BOOKADAPTION  values (5,6,208)
insert into BOOKADAPTION  values (5,2,210)
insert into BOOKADAPTION  values (6,7,206)
insert into BOOKADAPTION  values (7,3,207)
insert into BOOKADAPTION  values (7,3,206)
insert into BOOKADAPTION  values (8,3,207)
insert into BOOKADAPTION values(8,8,210)
insert into BOOKADAPTION values(8,5,209)

select * from BOOKADAPTION

create table ENROLL (
			regno varchar(10),
			course  int,
			sem int ,
			marks int,
			primary key(regno,course,sem),
			foreign key(regno) references STUDENT(regno)on delete cascade on update cascade,
			foreign key(course) references COURSE(course)on delete cascade on update cascade,
)

insert into ENROLL  values (111,1,5,59)
insert into ENROLL  values (111,2,5,70)
insert into ENROLL  values (111,3,5,75)
insert into ENROLL  values (112,1,5,49)
insert into ENROLL  values (113,2,5,80)
insert into ENROLL  values (114,3,7,79)
insert into ENROLL  values (115,4,3,79)

select * from ENROLL


//Lab Queries: 
1.	Produce a list of text books (include Course #, Book-ISBN,Book-title)
in the alphabetical order for courses offered by the ‘CS’ department
that use more than two books.


select C.dept AS DEPT,C.course as Course_No, B.bookISBN AS ISBN, T.title AS Title
from course C,BOOKADAPTION B,TEXTBOOK T
where C.course=B.course and B.bookISBN=T.bookISBN 
and C.course in( select C1.course 
                  from course C1,BOOKADAPTION B1,TEXTBOOK T1
				  where C1.course=B1.course and B1.bookISBN=T1.bookISBN
				  and C1.dept='CS' 
				  group by C1.course
				  having count(distinct B1.bookISBN)>=2)
order by T.title

// 2.	List any department that has all its adopted books published by a specific publisher

select C.dept,C.course,B.bookISBN, T.publisher
from BOOKADAPTION B, course C, TEXTBOOK T
where B.course=C.course and B.bookiSBN=T.bookISBN
select A.dept,B1.bookISBN,T.publisher
from course A,BOOKADAPTION B1,TEXTBOOK T
where A.course=B1.course and
B1.bookISBN= T.bookISBN and not exists (select bookISBN
			from BOOKADAPTION B, course C
			where B.course=C.course and C.dept=A.dept and
			bookISBN not in(select bookISBN
			       from TEXTBOOK
				   where publisher='McGraw'))

// 3.	List the bookISBNs and book titles of the department that has maximum number of students

select B.bookISBN, T.title
from BOOKADAPTION B, TEXTBOOK T, course CC
where B.bookISBN=T.bookISBN and CC.course=B.course and
cc.dept in( select C1.dept
             from course C1, enroll A
             where C1.course=A.course 
             group by C1.dept
             having count(A.regno)>= ALL(select count(E.regno)
                                     from course C,enroll E
                                     where C.course=E.course
                                      group by (C.dept)))
