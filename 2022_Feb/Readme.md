# 121. Best Time to Buy and Sell Stock

old question. But when I saw the question, I forget how to solve it.

we can only buy once and sell once. For each sell time, we must use the minimum price before as the buying point. So, we can for loop sell time and use a variable to store the minimal buying point before.

AC!

## 438. Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Interesting question. I have done before. I see I use std's solution. 

The std use a left and right pointer to store the substring. The std is a o(n) algorithm. each time, we move forward the right point, we will minus the new character once if it's in the count. 

yeah, actually we use a window between the string, we have a left and right. each time we let m[left++]++ and m[right++]--.

and we use a count, only if we iterate a character in the string p, we minus 1. when count == 0, we will put current left into the res.

AC

## 454. 4Sum II

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

8000000 => n^3

we can combine two arrays first then the 4sum turn into 2 sums.

and we can use a hashmap to store the second sum (nums3 and nums4)

Then, we iterate the first two sum, and use the hashmap to ensure the -1*element in the first two sum is exist or not. If it existed, we the value of the hashmap means the number of the sum. 

Overall, we need to iterate the first sum, the complexity is n^2.

AC

## 525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

the problem description make me confused. I wonder what is an subarray equal to to 0 and 1. Then I realize, the subarray contains the same number of 1 and 0.

1 <= nums.length <= 105
nums[i] is either 0 or 1.

therefore, we cannot have an n^2 algorithm. We need to have a n algorithm.

how about O(n) preprocess the prefix 1 and 0' sum;

and binary search the answer? oh, it seems do not satisfy the monotonous.

Let me see the std.

holy, when we have a one, we can add 1, when we have a zero, we can minus 1. and do the accumulated sum. if s = n, it means we have more n between 1 - current pos. So we need to delete n from 1 - some pos between 1 - current pos. How to know it, we can use a hashmap to record the sum -> pos; it means from 1 - pos we have a accumulated sum sum. Therefore, when we have s = n, we need to find n in the hashmap to find the answer. And because the answer is to get the maximal length. So, we need to let the pos in the hashmap as close as possible.

AC!

## 39. Combination Sum

done before.

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

* 1 <= candidates.length <= 30
* 1 <= candidates[i] <= 200
* All elements of candidates are distinct.
* 1 <= target <= 500

the maximal sum is 200*30 = 6000, therefore, can we use a DP array to store the possibilities combinations for all the sum?

it costs a lot to write the go...shit. I will still use C. let me see the std directly to see whether my answer is correct.

holy...the answer use dfs directly. Brute force!!! it's improtant to estimate the TC of brute force. 
