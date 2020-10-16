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