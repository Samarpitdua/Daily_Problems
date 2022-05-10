select 
	name,
	sum(if(distance is not null, distance, 0)) as travelled_distance
from users u 
left join rides r 
	on u.id = r.user_id 
group by name
order by 2 desc, 1 ;