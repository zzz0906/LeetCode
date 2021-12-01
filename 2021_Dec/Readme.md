## 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

classical DP problem. [done before](../Insights/198.md)

we can know that if we want to steal f[i], 

i-3,i-2,i-1,i

if we steal i, we can transfer from steal i-2, but if we steal i-2, we cannot steal i-3, thus, we can choose i-2 (not i-3 and i-1) or i-3
because we must steal i (assumption for dp[i]). Thus, f[i] can only transfered from i - 2 and i - 3. We shall prepare three elements in the array as init.