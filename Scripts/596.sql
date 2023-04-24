# Write your MySQL query statement below
select class from Courses group by class having count(distinct(student)) >= 5