CREATE DATABASE Lab5;
USE Lab5;
CREATE TABLE Publisher (
    PublisherID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Address nvarchar(50)
);

CREATE TABLE Book (
    BookID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Author nvarchar(50),
    Price integer,
    PublishedDate date,
    PublisherID nvarchar(50),
    FOREIGN KEY (PublisherID) REFERENCES Publisher(PublisherID)
);
-- Insert into Publisher table
INSERT INTO Publisher VALUES ('P01', 'Pearson', 'Bukit Jalil');
INSERT INTO Publisher VALUES ('P02', 'Deitel', 'Puchong');
INSERT INTO Publisher VALUES ('P03', 'Rainbow', 'Subang');

-- Insert into Book table
INSERT INTO Book VALUES ('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01');
INSERT INTO Book VALUES ('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01');
INSERT INTO Book VALUES ('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02');
INSERT INTO Book VALUES ('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P03');
SELECT * FROM Publisher WHERE Name LIKE 'R%';
SELECT * FROM Publisher WHERE Name LIKE '%n';
SELECT * FROM Book WHERE Name LIKE '%en%';
SELECT * FROM Book WHERE Author LIKE '%ce' ORDER BY Name DESC;
SELECT * FROM Publisher WHERE Address IN ('Puchong', 'Subang');
SELECT * FROM Book WHERE Price IN (50, 100);
UPDATE Publisher SET Address = 'Serdang' WHERE Name = 'Pearson';
UPDATE Book SET Price = 99 WHERE Name = 'English' AND Author = 'K.Vince';
ALTER TABLE Publisher ADD Telephone INT;
EXEC sp_rename 'Publisher.Telephone', 'ContactNumber', 'COLUMN';
ALTER TABLE Publisher DROP COLUMN ContactNumber;
DELETE FROM Book WHERE Name = 'Biology' AND Author = 'K.Vince';
CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,
    Name NVARCHAR(50),
    Email NVARCHAR(50)
);

-- Drop the Customer table
DROP TABLE Customer;
-- Create the new database
CREATE DATABASE MyDatabase;

-- Drop the entire database
DROP DATABASE MyDatabase;
