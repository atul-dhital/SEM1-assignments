CREATE DATABASE Lab6;
USE Lab6;
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
INSERT INTO Publisher (PublisherID, Name, Address) VALUES 
('P01', 'Pearson', 'Bukit Jalil'),
('P02', 'Deitel', 'Puchong'),
('P03', 'Rainbow', 'Subang');

-- Insert into Book table
INSERT INTO Book (BookID, Name, Author, Price, PublishedDate, PublisherID) VALUES 
('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01'),
('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01'),
('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02'),
('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P03');
SELECT TOP 2 * FROM Book WHERE Price < 130;
SELECT *, Price AS LowestPrice FROM Book WHERE Price = (SELECT MIN(Price) FROM Book);
SELECT *, Price AS HighestPrice FROM Book WHERE Price = (SELECT MAX(Price) FROM Book);
SELECT SUM(Price) AS TotalPrice FROM Book;
SELECT AVG(Price) AS AveragePrice FROM Book;
SELECT Name, Price FROM Book WHERE Price > (SELECT AVG(Price) FROM Book);
SELECT COUNT(*) AS TotalBooks FROM Book;
SELECT COUNT(*) AS BooksCostMoreThanRM60 FROM Book WHERE Price > 60;
SELECT COUNT(*) AS BooksCostMoreThanAverage FROM Book WHERE Price > (SELECT AVG(Price) FROM Book);
SELECT Author, COUNT(*) AS TotalBooksByAuthor FROM Book GROUP BY Author;
SELECT Author, SUM(Price) AS BookPriceByAuthor FROM Book GROUP BY Author;
