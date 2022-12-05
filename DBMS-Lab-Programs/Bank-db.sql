create database  bank139

use bank139

create table BRANCH(
		   	bname varchar(15)primary key,
			bcity varchar(15),
			assets real)


insert into BRANCH values('synd_nitte','karkala',200000)
insert into BRANCH values('Corp_nitte','karkala',300000)
insert into BRANCH values('PNB_nitte','karkala',100000)
insert into BRANCH values('Corp_mang','Mangalore',300000)
insert into BRANCH values('PNB_mang','Mangalore',500000)
insert into BRANCH values('state_udupi','Udupi',500000)
insert into BRANCH values('synd_udupi','Udupi',500000)
	
select * from BRANCH

create table ACCOUNT(
			accno int, 
			bname varchar(15),
			balance real,
			primary key(accno),
			foreign key(bname) references BRANCH(bname) on delete cascade on update cascade
		    )			

insert into ACCOUNT values(12345,'synd_nitte',6000)
insert into ACCOUNT values(12340,'synd_nitte',6000)
insert into ACCOUNT values(21345,'synd_nitte',10000)

insert into ACCOUNT values(14341,'Corp_nitte',15000)
insert into ACCOUNT values(14345,'Corp_nitte',15000)
insert into ACCOUNT values(12455,'Corp_nitte',17000)

insert into ACCOUNT values(13345,'PNB_nitte',11000)
insert into ACCOUNT values(13346,'PNB_nitte',11000)
insert into ACCOUNT values(13347,'PNB_nitte',11000)
insert into ACCOUNT values(13340,'PNB_nitte',11000)

insert into ACCOUNT values(15345,'synd_udupi',11000)

insert into ACCOUNT values(12453,'PNB_mang',17000)
insert into ACCOUNT values(21346,'PNB_mang',10000)
insert into ACCOUNT values(12450,'PNB_mang',17000)
insert into ACCOUNT values(12452,'PNB_mang',17000)

insert into ACCOUNT values(13245,'state_udupi',5000)
insert into ACCOUNT values(13241,'state_udupi',5000)
insert into ACCOUNT values(12375,'state_udupi',12000)
insert into ACCOUNT values(12377,'state_udupi',12000)
insert into ACCOUNT values(12378,'state_udupi',12000)
insert into ACCOUNT values(15342,'state_udupi',19000)
insert into ACCOUNT values(12451,'state_udupi',17000)

create table CUSTOMER(
			cname varchar(20)primary key,
			cstreet varchar(25),
			ccity varchar(20)
		     )

insert into CUSTOMER values('Rakesh','3rd main','karkala')
insert into CUSTOMER values('Ramesh','4th main','karkala')
insert into CUSTOMER values('Rajesh','4th block','mangalore')
insert into CUSTOMER values('Kareem','456 nagar','mangalore')
insert into CUSTOMER values('John smith','452 street','Udupi')

select * from CUSTOMER

create table DEPOSITOR(
			cname varchar(20),
			accno int,
			primary key(cname,accno),
			foreign key(cname) references CUSTOMER(cname) on delete cascade on update cascade,
			foreign key(accno) references ACCOUNT(accno) on delete cascade on update cascade,
			unique(accno)			
		      )

insert into DEPOSITOR values('Rakesh',12340)
insert into DEPOSITOR values('Rakesh',13345)
insert into DEPOSITOR values('Rakesh',14345)
insert into DEPOSITOR values('Rakesh',13346)
insert into DEPOSITOR values('Rakesh',15342)
insert into DEPOSITOR values('Rakesh',14341)

insert into DEPOSITOR values('Ramesh',12345)
insert into DEPOSITOR values('Ramesh',12375)
insert into DEPOSITOR values('Ramesh',12377)
insert into DEPOSITOR values('Ramesh',12378)
insert into DEPOSITOR values('Ramesh',13340)
insert into DEPOSITOR values('Ramesh',12451)
insert into DEPOSITOR values('Ramesh',12452)
insert into DEPOSITOR values('Ramesh',12455)

insert into DEPOSITOR values('Kareem',21346)
insert into DEPOSITOR values('Kareem',13245)

insert into DEPOSITOR values('Rajesh',15345)
insert into DEPOSITOR values('Rajesh',13241)

insert into DEPOSITOR values('John smith',21345)
insert into DEPOSITOR values('John smith',12453)
insert into DEPOSITOR values('John smith',13347)

create table LOAN (
			loanno int, 
			bname varchar(15),
			amount real,
			primary key(loanno),
			foreign key(bname) references BRANCH(bname) on delete cascade on update cascade
			 )


insert into LOAN values(1,'Corp_mang',12000)
insert into LOAN values(2,'Corp_mang',11000)
insert into LOAN values(3,'Corp_mang',10000)

insert into LOAN values(4,'Corp_nitte',16000)
insert into LOAN values(5,'Corp_nitte',13000)


insert into LOAN values(6,'PNB_mang',12000)
insert into LOAN values(11,'Corp_mang',10000)

insert into LOAN values(7,'state_udupi',20000)
insert into LOAN values(8,'state_udupi',23000)
insert into LOAN values(12,'synd_nitte',10000)

insert into LOAN values(9,'synd_nitte',32000)

insert into LOAN values(10,'PNB_nitte',12000)
insert into LOAN values(13,'state_udupi',12000)
insert into LOAN values(14,'synd_udupi',12000)
select * from LOAN

create table BORROWER(
			cname varchar(20),
			loanno int
			primary key(cname,loanno),
			foreign key(cname) references CUSTOMER(cname) on delete cascade on update cascade,
			foreign key(loanno) references LOAN(loanno) on delete cascade on update cascade,
			unique(loanno)
			)

insert into BORROWER values('John smith',1)
insert into BORROWER values('John smith',2)
insert into BORROWER values('John smith',3)
insert into BORROWER values('John smith',13)
insert into BORROWER values('John smith',14)

insert into BORROWER values('Kareem',4)
insert into BORROWER values('Kareem',5)
insert into BORROWER values('Rajesh',6)
insert into BORROWER values('Rajesh',11)
insert into BORROWER values('Rajesh',12)
insert into BORROWER values('Rajesh',7)
insert into BORROWER values('Rajesh',8)

insert into BORROWER values('Rakesh',9)
insert into BORROWER values('Ramesh',10)

select * from BORROWER 

select * from BRANCH

1. Find all the customers who have at least 2 
accounts at all the branches located in a specific city.

select C.cname 
from CUSTOMER  C 
where NOT EXISTS ((select B.bname 
					from  BRANCH B 
					where B.bcity  = 'karkala')
				EXCEPT
				(select A.bname 
				from ACCOUNT A, DEPOSITOR D, BRANCH B1 
				where D.accno = A.accno  
				and A.bname = B1.bname  
				and D.cname = C.cname  
				group by A.bname having count(*) >= 2))

2. Find all the customers who have accounts in at least 1 branch 
located in all the cities.

select C.cname 
from CUSTOMER C 
where NOT EXISTS(
				  (select distinct(B.bcity) 
				  from  BRANCH B)
                  EXCEPT
				   (select B1.bcity 
				   from BRANCH B1, ACCOUNT A ,DEPOSITOR D 
				   where A.bname = B1.bname 
				   and D.accno = A.accno 
				   and D.cname = C.cname   
				   group by B1.bcity having count(*) >=1)
                 )

3. Find all the customers who have accounts in at least 2 branches 
located in a specific city.

select C.cname 
from CUSTOMER  C 
where  EXISTS (select  count(distinct B.bname)
			   from BRANCH B, ACCOUNT A, DEPOSITOR D 
		       where A.bname = B.bname 
		       and D.accno = A.accno 
			   and B.bcity  = 'karkala' 
			   and D.cname = C.cname   
			   group by B.bcity having count(*) >=2
               )