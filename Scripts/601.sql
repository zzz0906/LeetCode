# Write your MySQL query statement below
with final as (select aid, apeople, bid, bpeople, d.id as cid, d.people as cpeople from (select a.id as aid, a.people as apeople, b.id as bid, b.people as bpeople from Stadium a inner join Stadium b on a.id + 1= b.id) c inner join Stadium d on c.aid + 2 = d.id where c.apeople >= 100 and c.bpeople >= 100 and d.people >= 100)
select * from Stadium where id in ((select aid from final union select bid from final) union select cid from final)