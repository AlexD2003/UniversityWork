
use hardwarestore
go
CREATE PROCEDURE AddColumnProcedure
AS
BEGIN
    IF NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'Customers' AND COLUMN_NAME = 'Address')
    BEGIN
        ALTER TABLE Customers
        ADD Address VARCHAR(100) NULL; 
    END
END
GO

CREATE PROCEDURE RemoveColumnProcedure
AS
BEGIN
    IF EXISTS (SELECT * FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'Customers' AND COLUMN_NAME = 'Address')
    BEGIN
        ALTER TABLE Customers
        DROP COLUMN Address;
    END
END
GO

CREATE PROCEDURE AddDefaultConstraintProcedure
AS
BEGIN
    ALTER TABLE Customers
    ADD CONSTRAINT DF_Customers_Email DEFAULT 'example@example.com' FOR Email;
END
GO

CREATE PROCEDURE RemoveDefaultConstraintProcedure
AS
BEGIN
    ALTER TABLE Customers
    DROP CONSTRAINT DF_Customers_Email;
END
GO

CREATE PROCEDURE CreateTableProcedure
AS
BEGIN
    CREATE TABLE NewTable (
        ID INT PRIMARY KEY,
        Description VARCHAR(100)
    );
END
GO

CREATE PROCEDURE DropTableProcedure
AS
BEGIN
    DROP TABLE IF EXISTS NewTable;
END
GO

CREATE PROCEDURE AddForeignKeyProcedure
AS
BEGIN
    ALTER TABLE Orders
    ADD CONSTRAINT FK_Orders_Customers FOREIGN KEY (Cid) REFERENCES Customers(Cid);
END
GO

CREATE PROCEDURE RemoveForeignKeyProcedure
AS
BEGIN
    ALTER TABLE Orders
    DROP CONSTRAINT FK_Orders_Customers;
END
GO

CREATE TABLE DatabaseVersion (
    VersionNumber INT PRIMARY KEY
);
INSERT INTO DatabaseVersion (VersionNumber) VALUES (1); 
go

create table Versions(versionFrom int, versionTo int, doProc nvarchar(100), undoProc nvarchar(100))
insert into Versions values
  (0, 1, 'AddColumnProcedure', 'RemoveColumnProcedure')
, (1, 2, 'AddDefaultConstraintProcedure', 'RemoveDefaultConstraintProcedure')
, (2, 3, 'CreateTableProcedure', 'DropTableProcedure')
, (3, 4, 'AddForeignKeyProcedure', 'RemoveForeignKeyProcedure')
go

CREATE or alter PROCEDURE ChangeDatabaseVersionProcedure
    @TargetVersion INT
AS
BEGIN
    DECLARE @CurrentVersion INT;
    SELECT @CurrentVersion = VersionNumber FROM DatabaseVersion;

    -- Handling forward transitions
    IF @TargetVersion > @CurrentVersion
    BEGIN
        WHILE @CurrentVersion <> @TargetVersion
        BEGIN
            DECLARE @DoProcedure NVARCHAR(100);

            SELECT @DoProcedure = doProc 
            FROM Versions 
            WHERE versionFrom = @CurrentVersion AND versionTo = @CurrentVersion + 1;

            IF @DoProcedure IS NOT NULL
            BEGIN
                EXEC sp_executesql @DoProcedure;
                PRINT 'Executed procedure: ' + @DoProcedure;
            END

            SET @CurrentVersion = @CurrentVersion + 1; -- Increment version number
			    UPDATE DatabaseVersion SET VersionNumber = @TargetVersion;
        END
    END
    -- Handling backward transitions
    ELSE IF @TargetVersion < @CurrentVersion
    BEGIN
        WHILE @CurrentVersion <> @TargetVersion
        BEGIN
            DECLARE @UndoProcedure NVARCHAR(100);

            SELECT @UndoProcedure = undoProc 
            FROM Versions 
            WHERE versionFrom = @CurrentVersion-1 AND versionTo = @CurrentVersion;

            IF @UndoProcedure IS NOT NULL
            BEGIN
                EXEC sp_executesql @UndoProcedure;
                PRINT 'Executed procedure to revert changes: ' + @UndoProcedure;
            END

            SET @CurrentVersion = @CurrentVersion - 1; -- Decrement version number
			    UPDATE DatabaseVersion SET VersionNumber = @TargetVersion;
        END
    END



    PRINT 'Database version reached the target version: ' + CAST(@TargetVersion AS VARCHAR(10));
END



EXEC ChangeDatabaseVersionProcedure @TargetVersion = 1;

