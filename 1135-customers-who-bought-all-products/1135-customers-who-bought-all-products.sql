# Write your MySQL query statement below
select customer_id from Customer
group by customer_id
having COUNT(DISTINCT product_key)=(Select count(*) from Product);