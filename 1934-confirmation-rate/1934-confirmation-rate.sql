select 
    Signups.user_id 
    ,
    if(count(action) > 0,
       round((select count(*) from Confirmations where action = 'confirmed' and user_id = Signups.user_id) / count(action), 2), 
       0)
    as 'Confirmation_rate'
from Signups
left join Confirmations on Signups.user_id = Confirmations.user_id
group by Signups.user_id, Confirmations.user_id;