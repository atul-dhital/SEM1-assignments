create database lab_one
create table student(StudentID nvarchar(50),Name nvarchar(50),Gender nvarchar(50),DOB date,Address nvarchar(50))
insert into student values('S01','Ali','Male','2-Feb-1996','Kauala Lampur')
insert into student values('S02','Nancy','Female','16-May-1997','Bukit Jalil')
insert into student values('S03','Melvin','Male','20-Nov-1998','Nepal')
insert into student values('S04','Angeline','Female','30-Dec-1995','Sri Petaling')
select *from student
