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
