# Write your MySQL query statement below
with nums as (
    select customer_number, count(*) as order_number from Orders group by customer_number
)
select customer_number from nums where order_number = (select max(order_number) from nums)