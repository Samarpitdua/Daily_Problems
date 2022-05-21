
select name , if(sum(distance) is null , 0 , sum(distance)) as travelled_distance from users left join rides on users.id = rides.user_id group by users.id order by 2 desc, 1;




















# select 
# 	name,
# 	sum(if(distance is not null, distance, 0)) as travelled_distance
# from users u 
# left join rides r 
# 	on u.id = r.user_id 
# group by name
# order by 2 desc, 1 ;