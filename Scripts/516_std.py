class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        t=s[::-1]  #idea is reverse t and compare t with s
        
        dp=[[0 for _ in range(len(s)+1)] for __ in range(len(s)+1)] #create dp array
        
        for i in range(1,len(s)+1):  #start from1 to match dp size, but compare s[i-1] and t [j-1]
            for j in range(1,len(s)+1):
                if s[i-1]!=t[j-1]:  #if not equal what do we want to do ? the question is asking to
				#find the longest palindromic subsequence and char @ S !=char @T, 
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]) #so we just take the max previous value we found before
                else:                                     #now they are equal so our palindrome can be bigger
                    dp[i][j]=1+dp[i-1][j-1]   #take previous + 1 
        return dp[-1][-1]