CREATE DATABASE Lab3;
USE Lab3;

-- Create Supplier table
CREATE TABLE Supplier (
    SupplierID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Address nvarchar(50)
);

-- Create Product table
CREATE TABLE Product (
    ProductID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Price integer,
    Quantity integer
);

-- Create Supplies table
CREATE TABLE Supplies (
    SuppliesID nvarchar(50) PRIMARY KEY,
    SupplierID nvarchar(50),
    ProductID nvarchar(50),
    Date date,
    Quantity integer,
    FOREIGN KEY (SupplierID) REFERENCES Supplier(SupplierID),
    FOREIGN KEY (ProductID) REFERENCES Product(ProductID)
);
ALTER AUTHORIZATION ON DATABASE::Lab3 TO [sa];
