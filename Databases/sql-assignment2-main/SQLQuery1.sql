--drop
use master
drop database hardwarestore
--create
CREATE DATABASE hardwarestore;
go
USE hardwarestore;
go 

CREATE TABLE Customers (
    Cid INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
	CNP VARCHAR(13) NOT NULL,
    Email VARCHAR(100)  NOT NULL
);

CREATE TABLE Products (
    Pid INT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,
    Price INT,
    StockQuantity INT
);

CREATE TABLE Orders (
    Oid INT PRIMARY KEY,
    OrderDate DATE NOT NULL,
    Cid INT FOREIGN KEY REFERENCES Customers(Cid)
);

--1-n relationship
CREATE TABLE OrderDetails (
    OrderDetailsId INT PRIMARY KEY NOT NULL,
    Oid INT FOREIGN KEY REFERENCES Orders(Oid),
    Pid INT FOREIGN KEY REFERENCES Products(Pid)
);

CREATE TABLE Employees (
    Eid INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    JobTitle VARCHAR(100) NOT NULL,
	ExperienceInYears INT,
	SalaryPerMonth INT NOT NULL
);

--m-n relationship
CREATE TABLE EmployeeOrderAssignments (
    EOAid INT PRIMARY KEY,
    Eid INT FOREIGN KEY REFERENCES Employees(Eid),
    Pid INT FOREIGN KEY REFERENCES Products(Pid)
);
--until here
--insert data into customers:
insert into Customers(Cid,FirstName,LastName,CNP,Email) values 
(4,'Alex','Domnit','5030602260020','alexdomnit@gmail.com'),
(5,'Burja','Irina','6040605560020','burjairina@gmail.com'),
(6,'Pop','Radu','5232622265820','popradu@gmail.com');

insert into Products(Pid,ProductName,Price,StockQuantity) values 
(11,'Razer keyboard',100,10),
(22,'Nvidia GPU',500,2),
(33,'Intel CPU',300,6);

insert into Orders(Oid,OrderDate,Cid) values 
(8,'2023-06-02',4),
(9,'2023-07-12',5),
(16,'2024-05-02',6);

CREATE TABLE OrderReviews (
    ReviewId INT PRIMARY KEY,
    Oid INT FOREIGN KEY REFERENCES Orders(Oid), -- Reference to Orders table
    ReviewText VARCHAR(MAX)
);
drop table OrderReviews

INSERT INTO OrderDetails (OrderDetailsId, Oid, Pid) values 
(1,1,1),
(2,2,2),
(3,3,3);

INSERT INTO Employees (Eid, FirstName, LastName, JobTitle, ExperienceInYears, SalaryPerMonth) VALUES
(101, 'John', 'Doe', 'Manager', 5, 5000),
(102, 'John', 'Doe', 'Manager', 5, 5000),
(103, 'Bob', 'Johnson', 'Salesperson', 2, 3000);

INSERT INTO EmployeeOrderAssignments (EOAid, Eid, Pid) VALUES
(1, 101, 1),
(2, 102, 2),
(3, 103, 3);

--update where first name starts with A
Update Customers
set FirstName='Sebi'
Where FirstName Like 'A___%'
--Update the price of products with 1000 where Pid is between 1 and 2
Update Products
set Price=1000 
where Pid between 1 and 2

--set stock quantity to 15 where id is 1 and price is 1000
Update Products
set StockQuantity=15
where Pid=1 and Price=1000

Update Orders
set Cid=NULL
where Cid<2

Update Orders
set Cid=1
where Cid IS NULL
select * from Orders

Delete from EmployeeOrderAssignments 
where Pid is null

Delete from Employees 
where SalaryPerMonth >=4500 or FirstName like 'K__%'

Delete from Orders
where OrderDate<'2020-01-01' and OrderDate > '2025-01-01'

--union query
select * from Customers
select c1.Cid,c1.FirstName,c1.LastName from Customers c1
where FirstName like 'S_%'
union
select c2.Cid,c2.FirstName,c2.LastName from Customers c2
where c2.Cid=3
order by c1.Cid desc
--intersect query
select * from Customers
select c1.Cid,c1.FirstName,c1.LastName from Customers c1
where FirstName like 'S_%'
intersect
select c2.Cid,c2.FirstName,c2.LastName from Customers c2
where c2.Cid=1
--except query
select * from Customers
select c1.Cid,c1.FirstName,c1.LastName from Customers c1
except 
select c2.Cid,c2.FirstName,c2.LastName from Customers c2
where c2.Email='popradu@gmail.com'
order by c1.Cid desc
--inner join
select Customers.FirstName, Orders.OrderDate, Products.ProductName
from Customers
inner join Orders on Customers.Cid = Orders.Cid
inner join OrderDetails on Orders.Oid = OrderDetails.Oid
inner join Products on OrderDetails.Pid = Products.Pid;
--left join
select Customers.FirstName, Orders.OrderDate
from Customers
left join Orders on Customers.Cid = Orders.Cid;
--right join
select Orders.OrderDate, OrderDetails.OrderDetailsId
from Orders
left join OrderDetails on Orders.Oid = OrderDetails.Oid;
--full join
select Customers.FirstName, Orders.OrderDate
from Customers
full join Orders on Customers.Cid = Orders.Cid;
--in query
select FirstName, LastName
from Customers
where Cid IN (
    select Cid
    from Orders
    where OrderDate > '2023-01-01'
);
--exists query
select FirstName, LastName from Customers C where C.Cid between 0 and 10 and exists (select * from Orders O where O.Cid = C.Cid)
;
--from
select top 3 A.Cid, A.FirstName, A.LastName
from (
    select C.Cid, C.FirstName, C.LastName
    from Customers C
    inner join Orders O ON C.Cid = O.Cid
    inner join OrderDetails OD ON O.Oid = OD.Oid
    inner join Products P ON OD.Pid = P.Pid
    where P.Price > 100
) as A;

select EOA.EOAid,AVG(P.price) AS Average
from EmployeeOrderAssignments EOA inner join Products P on EOA.Pid=P.Pid
group by EOA.EOAid
having AVG(P.price) > 100
--finding orders where stock quantity is not null
select O.Oid as OrderId,ODetails.Pid as ProductAssociated,sum(P.StockQuantity) as StockQuantity
from Orders O inner join OrderDetails ODetails on O.Oid=ODetails.OrderDetailsId inner join Products P on O.Oid=P.Pid
group by O.Oid,ODetails.Pid

--selecting thise that have the salary greater than minimum
select FirstName,LastName,AVG(SalaryPerMonth) from Employees
group by FirstName,LastName
having AVG(SalaryPerMonth)>(select MIN(SalaryPerMonth) from Employees)