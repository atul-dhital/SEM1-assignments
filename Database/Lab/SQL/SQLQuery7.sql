CREATE DATABASE Lab7;
USE Lab7;
-- Create Publisher table
CREATE TABLE Publisher (
    PublisherID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Address nvarchar(50)
);

-- Create Book table
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
INSERT INTO Publisher VALUES ('P01', 'Pearson', 'Bukit Jalil');
INSERT INTO Publisher VALUES ('P02', 'Deitel', 'Puchong');
INSERT INTO Publisher VALUES ('P03', 'Rainbow', 'Subang');

-- Insert data into Book table
INSERT INTO Book VALUES ('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01');
INSERT INTO Book VALUES ('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01');
INSERT INTO Book VALUES ('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02');
INSERT INTO Book VALUES ('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P03');
-- 4. Display a list of books published by 'Deitel'
SELECT * FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Deitel');

-- 5. Display a list of books published by 'Pearson' and written by 'S.Hanson'
SELECT * FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Pearson')
AND Author = 'S.Hanson';

-- 6. Display a list of books published by 'Pearson' which cost more than 80
SELECT * FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Pearson')
AND Price > 80;

-- 7. Display a list of books published by 'Pearson' which cost between 30 to 70 and written by 'J.Wenton'
SELECT * FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Pearson')
AND Price BETWEEN 30 AND 70 AND Author = 'J.Wenton';

-- 8. Count how many books are published by 'Rainbow'
SELECT COUNT(*) AS NumOfBook FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Rainbow');

-- 9. Sum the Price of books published by 'Pearson'
SELECT SUM(Price) AS TotalPrice FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Pearson');

-- 10. Find the average price of books published by 'Pearson'
SELECT AVG(Price) AS AvgPrice FROM Book WHERE PublisherID = (SELECT PublisherID FROM Publisher WHERE Name = 'Pearson');

-- 11. Display a list of books where its publisher’s address is 'Bukit Jalil'
SELECT * FROM Book WHERE PublisherID IN (SELECT PublisherID FROM Publisher WHERE Address = 'Bukit Jalil');
