# Write your MySQL query statement below
select user_id,concat(ucase(substr(users.name,1,1)),lcase(substr(users.name,2))) as name from Users order by user_id;