-- 1. Create a new database Lab 8
CREATE DATABASE Lab8;
USE Lab8;

-- 2. Create tables
CREATE TABLE Publisher (
    PublisherID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Address nvarchar(50)
);

CREATE TABLE Book (
    BookID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Author nvarchar(50),
    Price Integer,
    PublishedDate Date,
    PublisherID nvarchar(50) REFERENCES Publisher(PublisherID)
);

-- 3. Insert data into tables
INSERT INTO Publisher VALUES ('P01', 'Pearson', 'Bukit Jalil');
INSERT INTO Publisher VALUES ('P02', 'Deitel', 'Puchong');
INSERT INTO Publisher VALUES ('P03', 'Rainbow', 'Subang');
INSERT INTO Publisher VALUES ('P04', 'MacHill', 'Kuala Lumpur');

INSERT INTO Book VALUES ('B01', 'Maths', 'J.Wenton', 50, '2016-01-10', 'P01');
INSERT INTO Book VALUES ('B02', 'Science', 'S.Hanson', 100, '2016-02-12', 'P01');
INSERT INTO Book VALUES ('B03', 'English', 'K.Vince', 89, '2016-03-09', 'P02');
INSERT INTO Book VALUES ('B04', 'Biology', 'K.Vince', 150, '2016-04-24', 'P03');
INSERT INTO Book VALUES ('B05', 'Computing', 'J.Denzin', 180, '2011-07-15', NULL);

-- 4. Insert a new row into Publisher Table
INSERT INTO Publisher VALUES ('P04', 'MacHill', 'Kuala Lumpur');

-- 5. Insert a new row into Book Table
INSERT INTO Book VALUES ('B05', 'Computing', 'J.Denzin', 180, '2011-07-15', NULL);

-- 6. Inner Join Publisher and Book table
SELECT * FROM Book INNER JOIN Publisher ON Book.PublisherID = Publisher.PublisherID;

-- 7. Left Join Publisher with Book table, order by Publisher name
SELECT * FROM Publisher LEFT JOIN Book ON Publisher.PublisherID = Book.PublisherID ORDER BY Publisher.Name;

-- 8. Right Join Publisher with Book table, order by Book name
SELECT * FROM Publisher RIGHT JOIN Book ON Publisher.PublisherID = Book.PublisherID ORDER BY Book.Name;

-- 9. Full Outer Join Publisher and Book table
SELECT * FROM Publisher FULL OUTER JOIN Book ON Publisher.PublisherID = Book.PublisherID;

-- 10. UNION (PublisherID, Publisher name) union with (BookID, Book name)
SELECT PublisherID, Name FROM Publisher
UNION
SELECT BookID, Name FROM Book;

-- 11. Display a list of books published by 'Deitel'
SELECT * FROM Book INNER JOIN Publisher ON Book.PublisherID = Publisher.PublisherID WHERE Publisher.Name = 'Deitel';

-- 12. Display a list of books published by 'Pearson' and written by 'S.Hanson'
SELECT * FROM Book INNER JOIN Publisher ON Book.PublisherID = Publisher.PublisherID WHERE Publisher.Name = 'Pearson' AND Book.Author = 'S.Hanson';

-- 13. Display a list of books published by 'Pearson' which cost between 30 to 70 and written by 'J.Wenton'
SELECT * FROM Book INNER JOIN Publisher ON Book.PublisherID = Publisher.PublisherID WHERE Publisher.Name = 'Pearson' AND Book.Price BETWEEN 30 AND 70 AND Book.Author = 'J.Wenton';

-- 14. Display a list of books where its publisher’s address is 'Bukit Jalil'
SELECT * FROM Book INNER JOIN Publisher ON Book.PublisherID = Publisher.PublisherID WHERE Publisher.Address = 'Bukit Jalil';
