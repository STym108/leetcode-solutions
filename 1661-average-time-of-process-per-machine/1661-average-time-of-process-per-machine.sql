# Write your MySQL query statement below
select s.machine_id,round((
    sum(e.timestamp-s.timestamp)/(
     select count(distinct s.process_id ) 


    )
),3) as processing_time
from Activity as s
inner join Activity as e
on s.machine_id=e.machine_id
where s.process_id=e.process_id and s.activity_type='start'and e.activity_type='end'
group by s.machine_id
