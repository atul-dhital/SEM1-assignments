SELECT *
FROM Student
WHERE Gender = 'Female' AND CourseID = 'C02'
ORDER BY Name DESC;
SELECT Subject.*
FROM Subject
JOIN Course ON Subject.CourseID = Course.CourseID
WHERE Course.EntryQualification = '5 credits in O Level'
ORDER BY Subject.Name ASC;
SELECT Subject.*
FROM Subject
JOIN Course ON Subject.CourseID = Course.CourseID
WHERE Course.Name IN ('Degree', 'Master');
SELECT Subject.*
FROM Subject
JOIN Course ON Subject.CourseID = Course.CourseID
WHERE Course.Name IN ('Degree', 'Master');
SELECT Course.Name, COUNT(Subject.SubjectID) AS TotalSubjects
FROM Course
LEFT JOIN Subject ON Course.CourseID = Subject.CourseID
GROUP BY Course.Name;
SELECT Course.Name, COUNT(Student.StudentID) AS TotalStudents
FROM Course
LEFT JOIN Student ON Course.CourseID = Student.CourseID
GROUP BY Course.Name;
SELECT *
FROM Student
WHERE DOB < DATEADD(YEAR, -DATEDIFF(YEAR, DOB, GETDATE()), GETDATE());
SELECT *
FROM Student
ORDER BY DOB DESC;
SELECT Course.*
FROM Course
JOIN Student ON Course.CourseID = Student.CourseID
GROUP BY Course.CourseID, Course.Name, Course.EntryQualification
HAVING COUNT(Student.StudentID) > 1;
SELECT Course.*
FROM Course
JOIN Subject ON Course.CourseID = Subject.CourseID
GROUP BY Course.CourseID, Course.Name, Course.EntryQualification
HAVING COUNT(Subject.SubjectID) = 1;
