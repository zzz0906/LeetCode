## Number of Recent Calls

Easy question. Just I don't know what the question ask me to do. Just to find the the number of requests in the [t-3000; t]

I cannot use bucket because we cannot allocate a 10^9 array.

the t is increasing; which means we can push out the t-3000's value which cannot be accessed ever.

## Rotate List

Same as 61 which I have done before


## Binary Search

lower_bound? ...

It seems so easy.

YES ac... if lower_bound find it then return lower_bound index else return -1;

This problem help me with reviewing the c++ stl.

## Serialize and Deserialize BST

An open question. How to transfer BST to a string. Just like the 0 1 2 3 4 5 with index and each one has a value like

value,

JUST BFS & DFS... It's not a great question.

THE std use #val #left #right... format. It great

I want to change it to a array and then transfer it to a string. 

It seems in order traverse is the easiest way.

It's very hard to consider using input and output stream!

learn it!

## Minimum Number of Arrows to Burst Balloons

I read this question twice to understand what this question want to express. The ballon is around [x1,x2] you need to shot a point in the [x1,x2] then you can burst this ballon.

Some ballon is overlay you can shot one to busrt multiple.

-2^31 <= xstart < xend <= 2^31 - 1

This problem is to find the interval's intersection!

[[1,2],[2,3],[3,4],[4,5]]

2,3,4

when we shot 2,4 then we can burst all. Oh, DP?

Nope...I take the std's idea. 
First for the minimum ballon, it start has no overlap. which means 1,2 2,3 3,4 4,5 we can just shot 1,2 and we must shot it. Then, for an iterval. We must shot it. then it has a the end and the ballon whose start is less than its end can be shot either. 

But **after that**, we need to update end. because maybe there are situations start start end end then we want to shoot both two ballons, we need to let the shot point in the start-min(end,end).

HOLY!! two dimensions array can be sorted directly!

YES...it use recursive to compare two one-dimension array in two dimension array...

## Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

the smallerest means the smallest dad


Maybe we can first iterate over 'a'-'z' and find the corresponding places 

NO NO... we need record each character's position. It's a little complex...

Let me see the std's answer;

The std is so clever. He use a hash table to record the number of each character.

Then let we traverse the string, and when we face a char we need to compare it to the last character of the ans, if the last character of ans is bigger, which means current character is a better answer, but if the last character of the ans's count number is 0 which means it do not have any characters in the behind of the string. Therefore we cannot delete it.

(e.g., addc even if c < d but count d is zero therefore we cannot get the answer);

AC...So clever. The key point of this problem is

1. record the number of existing for this character
2. if last < current and there are last in the behind of the string we can delete last and add current
3. we can keep 2 until cannot find this last.

## Buddy Strings

Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

only two letters

o(n^2) enumerate each place of swap?


NO NO NO.

if they are buddy string.

1. eaqual a==a

2. we only have one pair (a[i] = b[j] b[i] = a[j])

AC! yes.

## Sort List

! leetcode 148 I have done it before. 

According to list, the best method is merge sort!

Fisrt we can use slow and fast to divide the list to two equal list

then we can sort it.

When the number of element is 1 then return it.

This step is perfect! merge(sort(l1),sort(l2))!

## House Robber II

It seems a classical DP problem.

0 1 2

=> 2 5 4 10 15

4 15

5 15

therefore the ans do not have to interval one, it can interval two element!

f[i,1] => grab ith max value

f[i,0] => do not grab ith

f[i,1] => max(f[i-2,0]+v[i],f[i-2,1]+v[i])

f[i,0] => max(f[i-1,1],f[i-1,0],f[i-2,1],f[i-2,0])

OH...we need to record whether choosing the first for the final.

A little complex...

let me see the std's solution.


OH... clever it compute twice once for only 1...end once for only 0...end-1

return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));

[0,num.size()-1) [1,nums.size()]

therefore! if (right - left <= 1) return nums[left];

And std use overload, really clever!

## Rotate Array

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Could you do it in-place with O(1) extra space?

erase and push front (insert begin?)

also **k = k % length** because we do not rotate again and again.

AC!

## Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted from left to right.

2. The first integer of each row is greater than the last integer of the previous row.

Just as the sorted list? But this problem is with more information?

in the last element, I need to try to keep removing the first element.

## Repeated DNA Sequences

187 I have done it before!

please refer to 186.

## Best Time to Buy and Sell Stock IV

DP!

188..I have done it before!

## Minimum Domino Rotations For Equal Row

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

brute force:
1. choose a fixed number
2. if the number is different then rotate it
3. repeat above process for each element of array

1 <= A[i], B[i] <= 6

...

It's so easy...just enumerate 1 to 6 for A and B

2*6*2 * 104

= 24*10^4 = 2.4 * 10^5

AC!

## Linked List Cycle II

see **142** in the daily training~

## Clone Graph

I have done it before... 133 done.

## Minimum Depth of Binary Tree

done it before...

111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Just DFS and fin the minimum depth. But it seems not fast?

## 132 Pattern

maybe we can record the 

n^3 enumerate

the std use priority_queue

how to do this?

132 pattern means ikj i is the smallest j is smaller

and the first element is j and we only need to record the element > j

when we find a new element we do following operations:

1. if this element is bigger than top of the stack means we have a 132' 3

2. then we need to roll back stack until we find a element which biggest but smaller than this element

3. in the above operations when we find a third element and the bigest second element we only need to record the second element
because we just need to find a value (the first element) < the second one

4. if we have a bigger third element than the top of the stack, we need to update to find the optimal value of the second element

I think this way is letting we record a second value (in the third place)

this solution is so clever!

## Bag of Tokens
If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.

If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.

which means I have two operations to let the tokes and score exchange.

It seems a greedy algorithm.

I have no more time to do this problem. Skip this problem today.

## Stone Game IV

It seems like a game theory

A,B will use their the best policy.

n-square_number-square_number

preprocess all square numbers in 1-10^5

Or it's a recursive? like 4-> 4-1 4-4

my recursion idea can be initialized as a DP

THE std use DP to solve this problem.

dp[i] true means alice win and false means bob win

dp[i-k*k] if there is a way let it be true then I will choose this method


## Champagne Tower

It's easy to think that after the second row, their champagn is output equal to all cup

1 2 2 1

so if it ask i,j

1+2+..i-1

1:2:2...:1

**In the first row, we do not satisfy these rules.**

**NO!!**

my idea has problems. I think the bowl is as the recurrence sequence!

Or I don't know. It's hard.

let me see std solutions.

std use dp. whcih means 1:2:...:2:1 is incorrect.

dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;

## Summary Ranges

Just scan it? and if it can continues to last one, then keep going on!

yes record the start end continuous! and determine whether it's continuous

Yes AC!