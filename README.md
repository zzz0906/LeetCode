# LeetCode Recording

Practicing my programming skill day by day
Record the consideration and analysis

## 10 Regular Expression Matching
~~Because it just contains '*', '.'.
I think we can detect if there are these two symbols in the pattern string. If there are not these two symbols we can just return whether these two strings are eaqual or not.~~

~~We use a **pointer** to point the position in s we want to compare. We use a **proced** variable to record the previous value for '*'.~~

~~If there is '*', that means we can fit a character with any times; then we repeat the pointer ++ until we cannot find the same one.~~

~~If there is '.', that means we can fit a random character. we can just add pointer;~~

~~If there is a albert, we need to compare it.~~

Then we can program the code in 10.cpp.

However
"aab"
"c*a*b"

Output
false

Expected
true

1. ~~We need to skip if we detect one character~~
2. ~~if the next char is '*' we need to skip too~~
3. ~~If we find all pattern but pointtos < s.length return false~~

Oh oh, it's not that easy; It's a **Recursion** or **Dynamic Programming** exercise. I refer to the **solution**:
I choose to use Recursion, let me figure it out

First if now position is '.' or a char then we can know that we just can match it with the string itself
we can if (p[now] != '*')
            return p[now] in {'.',s[point]} or match(pattern[now+1:],string[point+1:])

if the next position is a '*' 
So we can get zero pattern[now] then return match(pattern[now+2],string) or more than 1, therefore we can return match(pattern,sting[point+1:])

## 11 Container With Most Water

In this problem, it's easy to learn that we can just pick two points and calculate the answer (container water)

It's a n^2 solution.

Let me keep thinking, maybe we can just start from the middle? That's not correct.

Or we can start from the begin and end. Oh yes, we can.

if there is a better solution, we must move the point to the right left,if the value of the left or right is higher than ourselves. But how to calculate whether is better.

Then our complexity is n

We can just calculate the answer is (wide-1) * higer height or original height * (wide)

**BUT** Which point do we need to move? Right or Left?

Let me see, if the large on to move. we have no choice to make a better cotainer. Because the height is decided by the smaller one. and the wide become smaller (because of moving). So we need to move the smaller one. Then we can get the answer.


## 12 Interger to Roman
this is question for a integer that to a Roman
We can can just replace the data with related data.

If the number is < then a value then we should keep replace it. this is a typical replace question
Roman | value 
-----|-------
I	|1
IV	|4
V	|5
IX	|9
X	|10
XL	|40
L	|50
XC	|90
C	|100
CD	|400
D	|500
CM	|900
M	|1000
we can keep reduce until we cannot find a number that bigger than this number in the table.

## 15 3sum
if we just think about the brute force to find the three numbers, the time complexity is

N*(N-1)*(N-2)

It's too expensive. 
Let me think about sort first. Then we get a sorted array. We can just binary search it. (i,j,k)
if we fix an i, then we need to find a j and k, then we know that j + k = -i; we can find the k+i. we can use a bucket to store each value.

But you should pay attention to the existing of the value, Because the output cannot have the same value.

However fail, because it will have the probability to we choose a bucket and value is the same of value of the before value. that N^2 cannot be adapted.
________

Let use 3 pointers.j + k = -i if we point to i first, then we need to find the  j + k = -i if j + k > -i, this is a interesting question. the left + right is the most great sum. becuase the answer must between this two value. j....k. we must adjust the it between this two index. if (j + k) > -i k--; < -i then j++ until j == k;

this means the answer index must between the begin and end in the sorted array. 

## 16. 3Sum Closest
You have to find three number sum closet to the target offer, we can know that the we can use 15 problem

we need to answer close to the target. As the result, we can use a similar method as 15 to solve this problem. 
a+b+c = target a+b = target - c until find a most similar to the target. 

We keep using the o(n2) method to fix a value then find b and c. as the 15 describe.

## 18. 4sum
It more difficult to the last question.

Can we use last algorithms again? That's not true, we must use another algorithm. Because if we use above algorithm, the time complexity is too high.

However, similarly, we can use a+b = sum - (c+d) so we divide it to the 2 sum and 2 sum. Therefore, we can make a preprocess, first, we can add 2 numbers. for n numbers, we can get a C(n,2); pick 2 entity from the array. Then we choose to find a + b = target.

In this question, if I am a person, how to simulate I pick the 4 numbers. I can choose ith, jth (>i), choose k(>j), choose l (>k).

Then we can treat k,l like the 2 sum problem.

Therefore, it is a O(n^3). This is shown in 18std.cpp.

**Attention: Do not let the index out of the array, because leetcode will detect it, however our compiler do not **

However it TLE, we need to optimize it. I found that it's my programming problem, I use another guy's code in 18 std with the smae consideration. Then I pass this problem.

## 22 Generate Parentheses
