# Write your MySQL query statement below
Select max(num) as num
from MyNumbers
where num in (select num from MyNumbers group by num having count(*)<2);