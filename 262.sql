select
 b.request_at Day,
 round(sum(case when status like 'cancelled%' then 1 else 0 
             end)/count(*), 2) 'Cancellation Rate'
from users a , trips b
where a.banned = 'No'
and a.users_id = b.client_id 
and b.request_at >= '2013-10-01'
and b.request_at <= '2013-10-03'
group by b.request_at;