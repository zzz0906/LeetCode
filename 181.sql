# Write your MySQL query statement below
select e.Name as Employee from Employee e left join Employee m on e.ManagerID = m.Id where e.Salary > m.Salary