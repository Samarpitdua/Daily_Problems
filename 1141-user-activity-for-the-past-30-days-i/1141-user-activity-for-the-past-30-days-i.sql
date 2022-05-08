# # Write your MySQL query statement below
# select (activity_date) as day , count(distinct(user_id)) as active_users
# from
# activity
# group by activity_date
# having activity_date <= '2019-07-27' and activity_date > '2019-06-27';
# SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
# FROM Activity
# GROUP BY activity_date
# HAVING activity_date <= '2019-08-27' AND activity_date > '2019-06-27' ;

select activity_date as day, count(distinct user_id) as active_users 
from Activity
where datediff('2019-07-27', activity_date) <30
group by activity_date