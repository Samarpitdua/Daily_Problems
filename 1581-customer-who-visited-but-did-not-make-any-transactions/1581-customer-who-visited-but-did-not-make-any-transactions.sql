# Write your MySQL query statement below
# select v.customer_id , count(v.customer_id) as count_no_trans 
# from visits v 
# left join 
# transactions t
# on v.visit_id = t.visit_id
# where t.transaction_id is NULL
# ;
SELECT (V.CUSTOMER_ID) , COUNT(V.CUSTOMER_ID) AS COUNT_NO_TRANS FROM VISITS V  WHERE VISIT_ID NOT IN (SELECT DISTINCT (VISIT_ID) FROM TRANSACTIONS) GROUP BY CUSTOMER_ID;