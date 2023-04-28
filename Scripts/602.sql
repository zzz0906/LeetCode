with friends as (select id, count(friend) as num from
(select requester_id as id, accepter_id as friend
from requestaccepted
union all
select accepter_id as id, requester_id as friend
from requestaccepted) t
group by id
order by num desc limit 1)
select * from friends where num = (select max(num) from friends)
