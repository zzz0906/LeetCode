## Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

132 I have done before. 

```
NOPE!! **DP** again! f[i] represent from 0-i the minimum cuts needed.

for [0-i] we can transfered from [0-j] and [j+1,i] and we can know that the minimum cuts can be f[j]

and when f[j+1,i] is a palindrome then we can get the minimum cuts. we for loop all before value. 

Because the ansewr must be transfered from before cut in j and then cut in j!

Also, we use a p[i][j] to record whether it's a palindrome form i to j

and p[i][j] = (s[i] == s[j]) && p[i+1][j-1] 

Then we can update when p[j+1,i] then f[j] + 1
```

I think it's a memory-based search. Init it, if it's a palindrome f[i,j] = 1. O(n^2) for initialize.

And f[0..i] => f[0..j], f[j..i] => can be simplfied. Because, if we can split f[0..k] (k > j) and k..i is a palindrome. Then, we can ensure that 0..k must be f[k] + 1. Thus, we can use one dimensional for this question.