# record daily challenge in Leetcode
##  Largest Time for Given Digits

first we need to find the 23 ... 20 .. 19 .. 00

if we can choose 2 as the first it's ok

if there is no number <= 2 then return ""

then we need to choose second

if (first == 2) then the second must be 23 22 21 20
else 19 18 17 10 09 00

but we need to decide if theree is no 23 but has 19!

I still think we shall use dfs


YES! correct we need to enumerate each place of time but **attention for the special place for a time**