VI. The following tables are maintained by a book dealer:
AUTHOR (author-id: int, name: string, city: string, country: string)
PUBLISHER (publisher-id: int, name: string, city: string, country: string)
CATALOG (book-id: int, title: string, author-id: int, publisher-id: int, category-id: int, year: int, price: int)
CATEGORY (category-id: int, description: string)
ORDER-DETAILS (order-no: int, book-id: int, quantity: int)

1.	Find the author of the book which has maximum sales.
2.	Increase the price of the books published by a specific publisher by 10%
3.	Find the number of orders for the book that has minimum sales. 


create database bookshop

use bookshop

create table AUTHOR
		(
			authorid int primary key,
			aname  varchar(20),
			city	varchar(20),
			country	varchar(20)
		)


insert into AUTHOR values(110,'Elmasri','Houston','Canada')
insert into AUTHOR values(111,'sebesta','mangalore','India')
insert into AUTHOR values(112,'Elmasri','Houston','Canada')
insert into AUTHOR values(113,'Bharath K','Bangalore','India')
insert into AUTHOR values(114,'Willy Z','California','USA')
insert into AUTHOR values(115,'Salma','Dakha','Bangladesh')


create table PUBLISHER
		(
			pubid int primary key,
			pname  varchar(20),
			city	varchar(20),
			country	varchar(20)
		)	


insert into PUBLISHER values(201,'McGRAW','mangalore','India')
insert into PUBLISHER values(202,'Pearson','Bangalore','India')
insert into PUBLISHER values(203,'GKP','Bangalore','India')
insert into PUBLISHER values(204,'MediTech','Delhi','India')
insert into PUBLISHER values(205,'Sun','Ahmadbad','India')



create table CATEGORY
		(
			catid int primary key ,
	      	descript varchar(30),				
		)	


insert into CATEGORY values(1,'All children Books')
insert into CATEGORY values(2,'Cooking Books')
insert into CATEGORY values(3,'Popular Novels')
insert into CATEGORY values(4,'Small Story Books')
insert into CATEGORY values(5,'Medical Books')



create table CATALOGUE
		(
			bookid int primary key,
			title  varchar(20),
			pubid int,
			authorid int,
			catid int, 
			yr int,
			price int,
			foreign key(pubid) references PUBLISHER(pubid) on delete cascade on update cascade,
			foreign key(authorid) references AUTHOR(authorid) on delete cascade on update cascade,
			foreign key(catid) references CATEGORY(catid) on delete cascade on update cascade
		)	


insert into CATALOGUE values(301,'Panchatantra',201,111,1,2000,300)
insert into CATALOGUE values(302,'Vegetables',202,111,2,2000,400)
insert into CATALOGUE values(303,'Yogasana',203,112,5,2002,600)
insert into CATALOGUE values(304,'Stories of Village',204,113,4,2005,100)
insert into CATALOGUE values(305,'Triangle',205,114,3,2008,1000)
insert into CATALOGUE values(306,'Naughtiest Girl',201,110,3,2007,1500)
insert into CATALOGUE values(307,'Cookery',205,115,2,2006,100)

select * from catalogue

create table ORDER_DET
		(
			ordno int ,
			bookid int,
			qty int,
			primary key (ordno,bookid),
			foreign key(bookid) references CATALOGUE(bookid) on delete cascade on update cascade,			
		)	
		

insert into ORDER_DET values(1,301,10)
insert into ORDER_DET values(1,302,6)
insert into ORDER_DET values(1,307,23)

insert into ORDER_DET values(2,301,15)
insert into ORDER_DET values(2,304,11)

insert into ORDER_DET values(3,304,15)

insert into ORDER_DET values(4,301,3)
insert into ORDER_DET values(4,305,8)

insert into ORDER_DET values(5,303,20)
insert into ORDER_DET values(5,306,6)
insert into ORDER_DET values(5,305,7)

select * from AUTHOR
select * from PUBLISHER
select * from CATALOGUE
select * from CATEGORY
select * from ORDER_DET

1.  Find the author of the book which has maximum sales.

SOLUTION1:
select A.authorid, A.aname, A.city, sum(O. qty) as QTY_SUM   
from Author A, CATALOGUE  C, Order_Det O  
where A.authorid  =  C.authorid and C.bookid = O.bookid 
group by A.authorid, A.aname, A.city, C.bookid
having sum(O.qty) >= all (select sum(qty)  
						from Order_Det group by bookid)

2. Increase the price of the books published by a specific publisher by 10%

update  catalog set price = price * 1.1 
where pubid in ( select pubid from publisher where pname ='Pearson')


3. Find the number of orders for the book that has minimum sales. 

select count(*) as no_of_orders 
from order_det
where bookid in (select bookid  
                 from order_det  
				 group by bookid
	            having sum(qty) >= all (select sum(qty)  
				                       from order_det 
									   group by bookid))
group by bookid
