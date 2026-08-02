# Write your MySQL query statement below
select e1.employee_id as employee_id
from Employees as e1
left join Employees as e2 
on e1.manager_id=e2.employee_id
where e1.manager_id is not null and e1.salary<30000
and e2.employee_id is null
group by  e1.employee_id
order by e1.employee_id
