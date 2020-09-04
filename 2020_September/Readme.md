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

## Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

It's a slides window whose length is k then we need to record a heap to record the max and min

then we can know the max-min in this windows and compare to t.

This's easy to implement.

We also can use monotonic queue. 

because we know that the number > current number and the number exist before current number in the slides window.

This number cannot be the minimum.

Also the number < current number and the number exist before current number in the slides window. this cannot be the maximum.

we can use this idea to implement a max and min queue. and calculate the difference~


I consider this problem as a total different problem

**please read the problem description carefully**

It means the difference can reach t!! not at most t.

NO NO NO we just need to find the numbers.

THE STD use bucket.

```
In our case, the bucket looks like [0,t],[t+1,2t+1],…. Each time we distribute the current element nums[i] into a bucket, if this bucket is not empty then we find two elements that satisfy the two above requirements and we are done; otherwise we check two adjacent buckets to see whether any one of them is non empty and it contains an element whose value lies in the range of [nums[i]-t,nums[i]+t].
```

The STD use a map; and delete in O(n) and add in O(1); 

search in o(logn) find the lower bound of nums[i] - t and we compare whether it's bigger or smaller than the other value.

## Repeated Substring Pattern
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

we can iterate the number of substring existing

=> 2 3 4 ... k until length/k = 1 => length/k =2

length/k = 2 => the max is length (the copy exist length!)

if length % k != 0 we can continue

AC!

