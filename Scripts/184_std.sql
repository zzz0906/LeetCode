select d.Name as 'Department', e1.Name as 'Employee', e1.Salary FROM 
Employee e1 JOIN Department d ON e1.DepartmentId = d.Id 
WHERE Salary IN  
(SELECT MAX(Salary) FROM Employee e2 WHERE e1.DepartmentId = e2.DepartmentId);