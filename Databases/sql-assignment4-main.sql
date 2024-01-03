use hardwarestore
go

CREATE FUNCTION CheckOrderDate(@date DATE)
RETURNS BIT
AS
BEGIN
    DECLARE @b BIT

    IF (@date > '2024-01-01' OR @date < '2023-01-01')
        SET @b = 0
    ELSE
        SET @b = 1

    RETURN @b
END
GO

create function checkVarchar(@v varchar(50))
returns bit as
begin
declare @b bit
if @v LIKE '[a-z]%[a-z]'
set @b=1
else
set @b=0
return @b
end
go

create function checkInt(@n int)
returns int as
begin
declare @no int
if @n>1 and @n<=40
set @no=1
else
set @no=0
return @no
end
go 


CREATE or alter PROCEDURE InsertOrderDetails
	@Cid INT,
    @Pid INT,
	@OrderDate DATE
AS
BEGIN
	
	if(dbo.checkInt(@Cid)=1)
	Begin
		print('Order Id not valid')
		select * from Orders
	end
	declare @MaxOrderID INT;
	select @MaxOrderID = MAX(Oid)
	from Orders;
	declare @MaxOrderDetailsID INT;
	select @MaxOrderDetailsID = MAX(OrderDetailsId)
	from OrderDetails;
	insert into Orders(Oid,OrderDate,Cid) values (@MaxOrderID+1,@OrderDate,@Cid)
	insert into OrderDetails(OrderDetailsId,Oid,Pid) values (@MaxOrderDetailsID+1,@MaxOrderID+1,@Pid)
    
END

exec InsertOrderDetails 1,1,'05-05-2023'
select * from OrderDetails
select * from Orders

select * from OrderReviews

create or alter procedure InsertOrderReviews
	@ReviewId INT,
	@Oid INT,
	@ReviewText VARCHAR
as
begin
	if(dbo.checkVarchar(@ReviewText)=1)
		Print('Invalid text!')
		return
	declare @valOid int
	select top 1 @valOid=@Oid from Orders
	insert into OrderReviews(ReviewId,Oid,ReviewText) values (@ReviewId,@valOid,@ReviewText)
end

CREATE or alter VIEW OrderDetailsView AS
SELECT O.Oid, O.OrderDate, C.FirstName, C.LastName, P.ProductName, P.Price, ORV.ReviewText
FROM Orders O
INNER JOIN Customers C ON O.Cid = C.Cid
INNER JOIN OrderDetails OD ON O.Oid = OD.Oid
INNER JOIN Products P ON OD.Pid = P.Pid
LEFT JOIN OrderReviews ORV ON O.Oid = ORV.Oid;

select * from OrderDetailsView

create table LogTable (TriggerDateTime DATE, TriggerType varchar(10), TableName varchar(100), AffectedRecords int)
drop table LogTable

CREATE or alter TRIGGER OrdersTrigger
ON Orders
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    DECLARE @OperationType VARCHAR(10);

    IF EXISTS (SELECT * FROM inserted)
    BEGIN
        IF EXISTS (SELECT * FROM deleted)
            SET @OperationType = 'UPDATE';
        ELSE
            SET @OperationType = 'INSERT';
    END
    ELSE
        SET @OperationType = 'DELETE';
	if(@OperationType='INSERT')
	begin
    INSERT INTO LogTable (TriggerDateTime, TriggerType, TableName, AffectedRecords)
    VALUES (GETDATE(), @OperationType, 'Orders', (SELECT COUNT(*) FROM inserted));
	end
	else if(@OperationType='UPDATE')
	begin
	INSERT INTO LogTable (TriggerDateTime, TriggerType, TableName, AffectedRecords)
    VALUES (GETDATE(), @OperationType, 'Orders', (SELECT COUNT(*) FROM inserted));
	end
	else if(@OperationType='DELETE')
	begin
	INSERT INTO LogTable (TriggerDateTime, TriggerType, TableName, AffectedRecords)
    VALUES (GETDATE(), @OperationType, 'Orders', (SELECT COUNT(*) FROM deleted));
	end
END;

INSERT INTO Orders(Oid,OrderDate,Cid) values (999,'01-01-2023',1)
select * from Orders
update Orders set OrderDate='2023-11-28' where Cid%2=0
Delete from Orders where Oid=999
select * from LogTable

--clustered index seek
SELECT *
FROM Customers
WHERE Cid = 1;
--nonclustered index seek
SELECT *
FROM Orders
WHERE OrderDate = '2023-06-02';
--clustered index scan
SELECT *
FROM Employees
--nonclustered index scan
SELECT *
FROM Products
WHERE Price > 200;
--key lookup 
SELECT C.FirstName, O.OrderDate
FROM Customers C
JOIN Orders O ON C.Cid = O.Cid
WHERE C.Cid = 1;