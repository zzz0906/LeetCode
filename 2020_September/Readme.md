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

## Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Enumerate?

Try to greedily choose the smallest partition that includes the first letter. If you have something like "abaccbdeffed", then you might need to add b. You can use an map like "last['b'] = 5" to help you expand the width of your partition.

Greedy! we find a interval and we need to find how longest we can reach and no other existed char exist in the out of this interval.

**it's a union find algorithm but I just use brute force to find all the included interval. and ac.**

## All Elements in Two Binary Search Trees

We let two pointer point the two BST. Then we do the next operation in the last problem

I finish leetcode' 173 recently. It transfer BTS to array. we can transfer twice and merge array!

It's too complicated. I decided to use std.


JUST tranfer it into two array and merge it...my solution use less space but it's too complicated.


## Image Overlap

It's a problem that we need to slide a image to cover more 1

DFS? Just slide we can slide N*N

If we use dfs to get all posibilities, we may have duplicates

Therefore just use loop to get the right, down slides.

**attention:we need to slides A also slides B it's different you can think the last column if you just slide A the last column always in the outside except no slides but if you slides B the A left column can be inside! Or it means you can slides left and up (let B right and down!) **

YES! AC!

## Word Pattern

char => String ??

Just MAP. 

WE can use emplace_back and lambda function!

but ! abba , "dog dog dog dog" shall be false... It's a little bit different but I think it can be true loosely.

we can just add a string => char bi-direction is ac!!

## Sum of Root To Leaf Binary Numbers

I seem to have finished this problem. just dfs + when leaf calculate the binary to ten based number and add it to the answer;

AC!

## Compare Version Numbers

I have done 165 before. AC!

## Bulls and Cows

It's really a hard problem to understand.

But it seems easy. Just compare in each position

```
Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend
```

Why this become 1A1B? 

the numebr and position is correct called bulls

match the number but in wrong places call the cows

It's clear that we can get the all bulls. Then the rest number I need to determin the wrong position.

but we cannot use a number twice therefore I use two flag to record the number and position number we have used.

## Maximum Product Subarray

I have done 152 before! done. we need to record a minus and positive number which means the min and max

but! the max can be tranfer from min!

## Combination Sum III

DFS? use some trick and pruning in dfs?

YES...AC!

JUST DFS and determin in the k-1 numebr to do some pruning operations.

* target - current >= last number break (avoid duplicates number)

* target - current > 9 in the last number it cannot be > 9

## Insert Interval

union set?

Oh the original one must be the no overlap

It's too easy

TOO MANY BUG! I modify it according to the test cases again and again.

57?? I have done it before.

My past solution is just find all have the intersection interval with new intervals

And delete them and add other in the array

## House Robber

two adjacent house were broken on the same night. 

It's a clear DP problem. because we cannot rob the first and the second which means we may not choose the best at this time.

1 3 5 7

2 4 6 8???

It's so easy? maybe 1 4, 1 3

we still need to use DP

F[i] = F[i-2]+a[i],F[i-3]+a[i] for example 1 2 3 4 5 

5 <- 3,2 

yes! that's correct! I can do some dp problems!

## Length of Last Word

It's easy but too many bug...

for example, ' ' only a space means the split array is blank we need to solve it.

Therefore I add some condition in the code.

## Maximum XOR of Two Numbers in an Array

Math problem. Interesting. 

two numbers xor the number of different in its bit

a b c

a^b b^c a^c

It's so hard...let me do it precisely.

I understand we can use tried and for each number and use greedy to find the multiplier!

THE GREEDY IS SHOWN AS FOLLOW:

we first fix a number and transfer it to a bit number.

I find use python's dictionary to construct a tried is much easier.

BUT I still write C++ to finish this functionality. **So celever greedy idea.**

YES AC! I think this problem is hard.

## Robot Bounded In Circle

JUST simulation? 

I know the why this problem is so hard. We don't know the number of instructions then robot will go to the past place.

There must be a ans k; after the k the robot will be the original place otherwise it cannot return to the original place forever.

Because it can 4 time therefore it must 

The std repeat instructions once and determin whether it's in the original place || the direction is not north.

Strange...

I still use 4 times repeat and find whether it comes back to North and orginal place in this 4 repeat.

## Best Time to Buy and Sell Stock

the max minus min must be the answer but we need the max after the min

the after min is better than current min;

therefore we can record the past min; and we can use current - past_min and compare it to the ans;

## Sequential Digits

Does 78910 is correct? each digits which means not? therefore the biggest number is 9

therefore, for example, 4 digits - 8 digits 1234 2345

we can iterate over 4-8 digits!

AC!

## Unique Paths III

It's a clear a DP problem. Nope? 4 directions? maybe dfs? or dfs in memory? or bfs? I think bfs is fine.

Or dp from the end? or search from the end;

I think memory search from the end is the correct answer. We can record the 1 step place; 2 step place (let 2 step to one step place the number of answer ++)

BFS need to record the path we have run... It's so stupid. Can I use dp?

...STD use my solution.

walk over every non-obstacle square exactly once. please be careful...

I ignore this sentence; I am so stupid. 

I choose to use std's solution => just dfs

## Car Pooling

It's a interval increment problem?

And decide whether after this operation, if there is some interval is bigger than capacity.

Binary index tree?  Maybe we can use o(logN) to get the sum of interval and modify the number in o(logN)

Or we just use O(1*K) modify (Maybe segment tree can get better performance)

AC **1-5 5-7 which means the passagers can enter the car in 5 and the passagers in the can leave the car**

## Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

votes methods? >n/3*3 means there are 2 major elements at most.

oh std first we need to vote two numbers then we need to cheeck whether its existing number > n/3

also we need check whether this two numbers are not equal.

AC!

## Gas Station

Is this problem a greedy problem?

gas-cost means the most gas you can get in this interval. Choose the max diff?

NOPE...If we choose max diff at start maybe in the before starting point, we still can get some gas in this place...

we must start from a > 0 positive value. AND -3 2 -1 5; the interval sum cannot exist negative once.

Can we use prefix sum to do some accelerate operations? nope...

just enumerate? enumerate is fine...

YES, AC!

## Find the Difference

If we can use additional space; hashset

If we cannot use additional space; we need to search each char in the s? or some clever solution?

**XOR** char also can use xor!

## Largest Number

Solution is in 179; we can just consider it as string and use concat and compare who need in the first

## Teemo Attacking

Interesting! Just simulate? It seems easy.

ascending time series? means no equal value?

OR just iterate over the vector? and then record the last poison value?

YES AC! but we need to know that the time start from 0;

## Evaluate Division

Very interesting question. We have know the ration between multiple variables. After that, we need to use this relationships.

Maybe we can transfer in the single variable first?

but like this expression "bc"/"ad" how to solve it?

**single variable relationships?** 

Surprisely... It's a recurssion! 

BUT std has a problem. for example bc/cd = b/d

if we know the bc/bd and we want to know the answer of the b/d. If we do a operation like the std, the ans is -1

if we want to get a/e = a/c * c/d * d/e

my falut... A/B means only one variable, which means bc/bd means a variable called bc and another variable called bd.

## Subarray Product Less Than K

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

subarray use prefix?

1..i
1..j

1..j/1..i = i,j

enumarte for i,j

1000^5000 impossible...

another sol:

50000^3  impossible...

optimize it? : like in the second loop we can record a prefix product

50000^2 = 2500000000 TLE

OR DP? I don't know...

WE need a nlogn

e.g. 0-10 1-10 must can count answer ! therefore we can let i = j!

for 1 the next round j = 11

1-4: 1-4; 2-4; 3-4;

but we will repeat count...

IT's DP!

For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function.
1-1
2-1
3-1
4-2

1 + 1-2 + 1-3 + 2-3 + (must contain the j)

how to get opt(j)? 1-1 

opt(j) we know opt(j-1) => 2...j-1

opt(j-1)...j-1*j < k (optj) = optj-1

else while 

THE HINT is really great! record a place the top place we can reach that have the < k product

and the ans must include k

LET US SEE STD.

same us my above solution, but more gentle!

mantain a left for current index. 

left cur pro
0     0   1
0     0   3
0     1   6
0     2   12
0     3   24 > 15 ... 1    3   8
1     4   120 > 15    5    4   1

REALLY GENTLE THAN MsY CODE. LEARN IT!

## Word break

Same as 139 which I have finished before. please see in leetcode 139.

DP + HASH

## First Missing Positive

Your algorithm should run in O(n) time and uses constant extra space.

I think a solution. Find the maximum. and 1 to maximum to find the first value but find is in nlogn...

First find the minimum > 0

then done...

It seems too easy

minimum > 1 ans = 1


OR first we get all positive numbers

1+2+3+4

Surprise I have done this problem before...

I review my idea. It's too gorgeous.

I use the original array as the bucket. And keep swaping until each number < length to its corrospoding position!