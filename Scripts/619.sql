# Write your MySQL query statement below

select max(num) as num from (select count(*) as exist, num from MyNumbers group by num) a where exist = 1
