CREATE DATABASE Lab_two;
--USE Lab2;
-- publishers table
CREATE TABLE Publishers (
    publishersID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Address nvarchar(50)
);

-- books table
CREATE TABLE books (
    booksID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Author nvarchar(50),
    Price integer,
    PublishedDate date,
    publishersID nvarchar(50),
    FOREIGN KEY (publishersID) REFERENCES publishers(publishersID)
);
-- Insert data into publishers table
INSERT INTO publishers VALUES ('P01', 'Pearson', 'Bukit Jalil');
INSERT INTO publishers VALUES ('P02', 'Deitel', 'Puchong');
INSERT INTO publishers VALUES ('P03', 'Rainbow', 'Subang');
select *from publishers

-- Insert data into books table
INSERT INTO books VALUES ('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01');
INSERT INTO books VALUES ('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01');
INSERT INTO books VALUES ('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02');
INSERT INTO books VALUES ('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P02');
select *from books


-- This will result in an error
DELETE FROM publishers WHERE publishersID = 'P02';


-- This will work
DELETE FROM publishers WHERE publishersID = 'P03';


-- This will work
DELETE FROM books WHERE booksID = 'B03';
