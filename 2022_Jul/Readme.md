## 199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

I have done this question before. But when I see the question, I still have no idea dealing with this question. 

my raw idea is use an array to store each levels's value and when a new value comes in we just pop the old value out.

let me see my std answer before.

I use a bfs. And bfs each depth in the queue and repush all the son in queue again. It's clear that the right side node will be put in the queue after the left side. Thus, the back of the queue each time will be the answer！
## 629. K Inverse Pairs Array

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

It seems that we can use brute force + iteration. The minimal answer will be 0 as 1,2,3,4... and maximal answer will be n,n-1,.... = 1 + 2 + ... n - 1 = (n)*(n-1) / 2. I have no idea how to do it. let me see the std. 

The DP rule is interesting. n,k is the sum of n,k-1 and n-1,k. But the hardest part is to find patterns in dp table itself. We have to use brute force to print dp table. When k >= n, the ansewr shall be ans+= 10^9 + 7 - f(n-1,k-n).
## 1074. Number of Submatrices That Sum to Target

I have finished this. First, transform the matrix into prefix sum.

The std use two pointer to scan the column from i to j and use k to scan the x.  The std enumeration way is abstract. Because the column scan is fixed, the submatrix is continous, thus we still can use a column's row-prefix. We started from the first row use rows-prefix to get the sum from i to j in o(1) and accumualte it. And the submatrix  == current value - past accumulated row's sum. Because current value is accumulated of row's sum. And cur value - past accumulated row's sum = target means the diff of prefix sum == sub matrix equal to target. Therefore we can use a map to record the number of past prefix sum. And the current prefix sum - target to get the number of answer.

Very brillant idea! AC!