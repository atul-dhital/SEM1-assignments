CREATE DATABASE Lab4;
USE Lab4;
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
-- Insert data into Publisher table
INSERT INTO Publisher (PublisherID, Name, Address)
VALUES 
    ('P01', 'Pearson', 'Bukit Jalil'),
    ('P02', 'Deitel', 'Puchong'),
    ('P03', 'Rainbow', 'Subang');

-- Insert data into Book table
INSERT INTO Book (BookID, Name, Author, Price, PublishedDate, PublisherID)
VALUES 
    ('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01'),
    ('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01'),
    ('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02'),
    ('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P03');
	SELECT * FROM Publisher;
	SELECT Name, Author FROM Book;
SELECT Name, Author FROM Book;
SELECT * FROM Book WHERE PublisherID = 'P01';
SELECT * FROM Book WHERE Price > 100;
SELECT * FROM Book WHERE Price <= 100;
SELECT * FROM Book WHERE Price BETWEEN 100 AND 200;
SELECT * FROM Book WHERE Price NOT BETWEEN 100 AND 200;
SELECT * FROM Book WHERE Price NOT BETWEEN 100 AND 200;
SELECT * FROM Publisher WHERE Address = 'Puchong' OR Address = 'Subang';
SELECT * FROM Publisher ORDER BY Name ASC;
SELECT * FROM Book ORDER BY Name DESC;
