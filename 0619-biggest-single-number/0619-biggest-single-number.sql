# Write your MySQL query statement below
select max(m.num) as num
from (
    select num ,count(*) as freq
    from MyNumbers as m
    group by num
) as m
where m.freq=1