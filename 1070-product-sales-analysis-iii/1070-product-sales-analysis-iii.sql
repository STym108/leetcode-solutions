# Write your MySQL query statement below
select s1.product_id,s1.year as first_year,
s1.quantity,s1.price
from sales as s1
join(
    select product_id,min(year) as first_year
    from sales 
    group by product_id
) t
on s1.product_id=t.product_id
and s1.year=t.first_year



