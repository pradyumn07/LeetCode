# Write your MySQL query statement below
select r.contest_id,Round(count(distinct r.user_id)*100/(select count(*) from Users),2) as percentage
from Users u join Register r
on u.user_id=r.user_id
group by contest_id
order by percentage desc,contest_id