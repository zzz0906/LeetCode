select mm.Department, Name as 'Employee', Salary
from (Employee inner join 
(select e.DepartmentId, d.Name as 'Department',e.name as 'Employee', max(Salary) as 'maxSalary' from Employee e inner join Department d on e.DepartmentId = d.Id group by d.Name) mm
on Employee.Salary = mm.maxSalary) 