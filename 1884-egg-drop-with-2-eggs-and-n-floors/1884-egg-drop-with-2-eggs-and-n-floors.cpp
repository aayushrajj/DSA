class Solution {
public:
    int dp[3][1002];
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
    
    int solve(int e,int n){
        if(e==1)
            return dp[e][n] = n;
        if(n<=1)
            return dp[e][n] = n;
        
        if(dp[e][n]!=-1)
            return dp[e][n];
        int minAns = INT_MAX;
        for(int k=1;k<=n;k++){
            int temp = 1 + max( solve(e-1,k-1) , solve(e,n-k) );
            minAns = min(minAns,temp);
        }
        
        return dp[e][n] = minAns;
    }
};