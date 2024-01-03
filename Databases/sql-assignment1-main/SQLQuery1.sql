use master
drop database hardwarestore

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
    CustomerID INT NOT NULL,
    OrderDate DATE NOT NULL,
    Cid INT FOREIGN KEY REFERENCES Customers(Cid)
);

--1-n relationship
CREATE TABLE OrderDetails (
    OrderDetailID INT PRIMARY KEY,
    OrderID INT NOT NULL,
    ProductID INT NOT NULL,
    Quantity INT,
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

use master
drop database hardwarestore

