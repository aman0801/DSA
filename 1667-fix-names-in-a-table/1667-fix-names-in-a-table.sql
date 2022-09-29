# Write your MySQL query statement below
select user_id, CONCAT(upper(substr(name, 1, 1)), lower(substr(name,2,length(name))))
       AS name
FROM Users ORDER BY user_id;                                     
                           
       