select distinct(Tree.id), 
case when Tree.p_id is null then "Root" 
when tmp.p_id is null then "Leaf" 
else "Inner" end as type 
from Tree left join Tree tmp on Tree.id = tmp.p_id