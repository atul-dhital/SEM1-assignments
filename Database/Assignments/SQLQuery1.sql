//create tabels
-- Create Publishers table
CREATE TABLE Publishers (
    PublisherID INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Address VARCHAR(255),
    -- add other attributes
);

-- Create Books table
CREATE TABLE Books (
    ISBN VARCHAR(13) PRIMARY KEY,
    Title VARCHAR(255) NOT NULL,
    Category VARCHAR(50),
    PublisherID INT,
    Price DECIMAL(10, 2),
    ReleaseDate DATE,
    
    FOREIGN KEY (PublisherID) REFERENCES Publishers(PublisherID)
    -- add other attributes
);

-- Create Customers table
CREATE TABLE Customers (
    MemberID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Address VARCHAR(255),
    ContactNumber VARCHAR(20),
    
    -- add other attributes
);

-- Create Orders table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    MemberID INT,
    OrderDate DATE,
   
    FOREIGN KEY (MemberID) REFERENCES Customers(MemberID)
    -- add other attributes
);

-- Create Invoices table
CREATE TABLE Invoices (
    InvoiceID INT PRIMARY KEY,
    OrderID INT,
    InvoiceDate DATE,
    TotalAmount DECIMAL(10, 2),

    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
    -- add other attributes
);

-- Create Feedback table
CREATE TABLE Feedback (
    FeedbackID INT PRIMARY KEY,
    MemberID INT,
    ISBN VARCHAR(13),
    Score INT CHECK (Score >= 0 AND Score <= 10),
    Comment VARCHAR(255),
    FOREIGN KEY (MemberID) REFERENCES Customers(MemberID),
    FOREIGN KEY (ISBN) REFERENCES Books(ISBN)
    -- add other attributes
);

-- Create ShoppingCart table
CREATE TABLE ShoppingCart (
    MemberID INT,
    ISBN VARCHAR(13),
    Quantity INT,
    Price DECIMAL(10, 2),
    PRIMARY KEY (MemberID, ISBN),
    FOREIGN KEY (MemberID) REFERENCES Customers(MemberID),
    FOREIGN KEY (ISBN) REFERENCES Books(ISBN)
    -- add other attributes
);

-- add other necessary tables based on your scenario


//insert into tables dml
-- Sample values for Publishers table
INSERT INTO Publishers (PublisherID, Name, Address)
VALUES
(1, 'ABC Publishing', '123 Main Street, Cityville'),
(2, 'XYZ Publishers', '456 Oak Avenue, Townsville'),
(3, 'DEF Books Ltd.', '789 Maple Road, Villagetown');

-- Sample values for Books table
INSERT INTO Books (ISBN, Title, Category, PublisherID, Price, ReleaseDate)
VALUES
('ISBN001', 'The Art of Programming', 'Programming', 1, 29.99, '2023-01-15'),
('ISBN002', 'Data Science Essentials', 'Data Science', 2, 39.99, '2023-02-20'),
('ISBN003', 'The Mystery of Time', 'Mystery', 1, 24.99, '2023-03-10'),
('ISBN004', 'Space Exploration', 'Science', 3, 49.99, '2023-04-05'),
('ISBN005', 'Love in the Digital Age', 'Romance', 2, 19.99, '2023-05-15'),
('ISBN006', 'History of C--ivilization', 'History', 1, 34.99, '2023-06-20');

-- Sample values for Customers table
INSERT INTO Customers (MemberID, FirstName, LastName, Address, ContactNumber)
VALUES
(101, 'John', 'Doe', '456 Pine Street, Cityville', '123-456-7890'),
(102, 'Alice', 'Smith', '789 Cedar Avenue, Townsville', '456-789-0123'),
(103, 'Bob', 'Johnson', '123 Oak Road, Villagetown', '789-012-3456'),
(104, 'Eva', 'Brown', '567 Elm Lane, Hamletville', '012-345-6789'),
(105, 'David', 'Lee', '890 Birch Boulevard, Suburbia', '234-567-8901'),
(106, 'Grace', 'Miller', '234 Walnut Dr--ive, Countryside', '345-678-9012');

-- Sample values for Orders table
INSERT INTO Orders (OrderID, MemberID, OrderDate)
VALUES
(201, 101, '2023-01-20'),
(202, 102, '2023-02-25'),
(203, 103, '2023-03-15'),
(204, 104, '2023-04-10'),
(205, 105, '2023-05-20'),
(206, 106, '2023-06-25');

-- Sample values for Invoices table
INSERT INTO Invoices (InvoiceID, OrderID, InvoiceDate, TotalAmount)
VALUES
(301, 201, '2023-01-22', 29.99),
(302, 202, '2023-02-28', 39.99),
(303, 203, '2023-03-18', 24.99),
(304, 204, '2023-04-12', 49.99),
(305, 205, '2023-05-22', 19.99),
(306, 206, '2023-06-28', 34.99);

-- Sample values for Feedback table
INSERT INTO Feedback (FeedbackID, MemberID, ISBN, Score, Comment)
VALUES
(401, 101, 'ISBN001', 8, 'Great book!'),
(402, 102, 'ISBN002', 9, 'Excellent content'),
(403, 103, 'ISBN003', 7, 'Enjoyable read'),
(404, 104, 'ISBN004', 10, 'Highly recommended'),
(405, 105, 'ISBN005', 6, 'Interesting perspect--ive'),
(406, 106, 'ISBN006', 8, 'Well-written history');

-- Sample values for ShoppingCart table
INSERT INTO ShoppingCart (MemberID, ISBN, Quantity, Price)
VALUES
(101, 'ISBN001', 2, 29.99),
(102, 'ISBN002', 1, 39.99),
(103, 'ISBN003', 3, 24.99),
(104, 'ISBN004', 1, 49.99),
(105, 'ISBN005', 2, 19.99),
(106, 'ISBN006', 1, 34.99);


--//dml

--Certainly! Below are some sample Data Manipulation Language (DML) queries that correspond to the specified requirements:


--i. A list of latest books sent by various publishers based on a monthly basis:

-- Assuming 'ReleaseDate' is a DATE column in the Books table
SELECT b.Title, b.ReleaseDate, p.Name AS Publisher
FROM Books b
JOIN Publishers p ON b.PublisherID = p.PublisherID
WHERE MONTH(b.ReleaseDate) = 1; -- Replace 1 with the desired month

ii. A list of books ordered by the store manager from various publishers based on a monthly basis:

-- Assuming 'OrderDate' is a DATE column in the Orders table
SELECT b.Title, o.OrderDate, p.Name AS Publisher
FROM Books b
JOIN Orders o ON b.ISBN = o.ISBN
JOIN Publishers p ON b.PublisherID = p.PublisherID
WHERE MONTH(o.OrderDate) = 1; -- Replace 1 with the desired month

--iii. Produce a record of invoices for various publishers:

SELECT i.InvoiceID, i.InvoiceDate, p.Name AS PublisherName, p.Address AS PublisherAddress, i.TotalAmount
FROM Invoices i
JOIN Orders o ON i.OrderID = o.OrderID
JOIN Books b ON o.ISBN = b.ISBN
JOIN Publishers p ON b.PublisherID = p.PublisherID;

--iv. A list of all customer records who are registered members in TU E-Bookstore:

SELECT *
FROM Customers;
v. A list of purchased books that have been del--ivered to members:



SELECT c.MemberID, c.FirstName, c.LastName, c.Address, c.ContactNumber, b.ISBN, b.Title, p.Quantity, p.Del--iveryDate, p.Status
FROM Purchases p
JOIN Customers c ON p.MemberID = c.MemberID
JOIN Books b ON p.ISBN = b.ISBN;

--vi. List of books based on specific categories:

-- Assuming 'Category' is a column in the Books table
SELECT Category, ISBN, Title, Quantity
FROM Books
WHERE Category = 'Science Fiction';

--vii. List of total number of books for each category of books:


SELECT Category, COUNT(*) AS TotalBooks
FROM Books
GROUP BY Category;

--viii. A list of total books and their total price as added by members in the shopping cart:


SELECT c.MemberID, c.FirstName, c.LastName, c.Address, c.ContactNumber, s.ISBN, s.Quantity, s.Price
FROM ShoppingCart s
JOIN Customers c ON s.MemberID = c.MemberID;

--ix. A list of books with the number of various feedbacks

SELECT b.ISBN, b.Title, f.Score, COUNT(*) AS FeedbackCount
FROM Feedback f
JOIN Books b ON f.ISBN = b.ISBN
GROUP BY b.ISBN, b.Title, f.Score;



