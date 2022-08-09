class Solution {
    int M=1e9+7;
    int dp[1005][1005];
    int f(int n, int k){
        if(k==0) return 1;
        if(k<0) return 0;
        if(n<=1) return 0;
        if(k>(n*(n-1)/2)) return 0;   // reversed seq 54321 has k =10 =(1+2+3+4), hence maxlimit of k is n*(n-1)/2 
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans=0;
        //for(int i=0;i<min(n,k+1);i++)         // Normal dp explained in many YouTube videos
        {
            //ans+= f(n-1,k-i);
            
            ans= (f(n,k-1)+f(n-1,k)) %M;                 // just left and upper cell of (n,k)
            if(k>=n)                 
            ans+= M - f(n-1,k-n);   // Idea is to find patterns in dp table itself (Hardest part)
            ans%=M;
        }
        return dp[n][k]= ans;
    }
    public:
        int kInversePairs(int n, int k) {
            memset(dp,-1,sizeof(dp));

            // for(int i=0;i<10;i++){                 // Way to find patterns in dp table itself
            //     for(int j=0;j<=(i*(i-1)/2);j++){
            //         cout<< f(i,j)<<" ";
            //     }
            //     cout<<endl;
            // }
            return f(n,k);
        }
};