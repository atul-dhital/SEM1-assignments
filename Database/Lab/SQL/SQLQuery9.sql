-- 1. Create a new Database Lab9
CREATE DATABASE Lab9;
GO

-- 2. Use the Lab9 database
USE Lab9;
GO

-- 3. Create 3 tables
CREATE TABLE Course (
    CourseID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    EntryQualification nvarchar(50)
);

CREATE TABLE Student (
    StudentID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    Gender nvarchar(50),
    DOB Date,
    CourseID nvarchar(50) FOREIGN KEY REFERENCES Course(CourseID)
);

CREATE TABLE Subject (
    SubjectID nvarchar(50) PRIMARY KEY,
    Name nvarchar(50),
    CourseID nvarchar(50) FOREIGN KEY REFERENCES Course(CourseID)
);

-- 4. Insert data
INSERT INTO Course (CourseID, Name, EntryQualification) VALUES
('C01', 'Diploma', '3 credits in O Level'),
('C02', 'Degree', '3 credits in A Level'),
('C03', 'Master', 'Degree in any computing field'),
('C04', 'Foundation', '5 credits in O Level');

INSERT INTO Student (StudentID, Name, Gender, DOB, CourseID) VALUES
('ST01', 'Helen', 'Female', '1999-02-02', 'C01'),
('ST02', 'Karen', 'Female', '2000-09-15', 'C02'),
('ST03', 'Peter', 'Male', '1997-04-28', 'C02'),
('ST04', 'Shaun', 'Male', '2001-06-30', 'C03');

INSERT INTO Subject (SubjectID, Name, CourseID) VALUES
('SU01', 'SAD', 'C01'),
('SU02', 'IDB', 'C01'),
('SU03', 'ISWE', 'C02'),
('SU04', 'CPP', 'C02'),
('SU05', 'Java', 'C03'),
('SU06', 'NNT', 'C04'),
('SU07', 'DAS', 'C04');

-- 5. Display StudentID, Name, and Age (derive Age from DOB)
SELECT StudentID, Name, DATEDIFF(YEAR, DOB, GETDATE()) AS Age FROM Student;

-- 6. List all students whose age is more than 18
SELECT StudentID, Name, DATEDIFF(YEAR, DOB, GETDATE()) AS Age
FROM Student
WHERE DATEDIFF(YEAR, DOB, GETDATE()) > 18;

-- 7. Inner Join Course, Student, and Subject table
SELECT *
FROM Course
INNER JOIN Student ON Course.CourseID = Student.CourseID
INNER JOIN Subject ON Course.CourseID = Subject.CourseID;

-- 8. Join all columns from Course and Subject table without using the keyword 'JOIN'
SELECT *
FROM Course, Subject
WHERE Course.CourseID = Subject.CourseID;

-- 9. Join all columns from Course, Student, and Subject table without using the keyword 'JOIN'
SELECT *
FROM Course, Student, Subject
WHERE Course.CourseID = Student.CourseID
  AND Course.CourseID = Subject.CourseID;

-- 10. Left Join Course with Student table, order by Course name (Course is left, Student is right)
SELECT *
FROM Course
LEFT JOIN Student ON Course.CourseID = Student.CourseID
ORDER BY Course.Name;

-- 11. Right Join Course with Student table, order by Student name (Course is left, Student is right)
SELECT *
FROM Course
RIGHT JOIN Student ON Course.CourseID = Student.CourseID
ORDER BY Student.Name;
