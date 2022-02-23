class Solution {
public:
    
    int minCut(string s){
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    dp[i][j]=1;
                else if(g==1 && s[i]==s[j])
                    dp[i][j]=1;
                else if(s[i]==s[j] && dp[i+1][j-1]==1)
                    dp[i][j]=1;
            }
        }
        
        vector<int> store(n);
        store[0]=0;
        for(int j=1;j<n;j++){
            if(dp[0][j]==1)
                store[j]=0;
            else{
                int minans = INT_MAX;
                for(int i=j;i>=1;i--){
                    if(dp[i][j]==1){
                        if(store[i-1]<minans)
                            minans = store[i-1];
                    }
                }
                store[j] = minans+1;
            }
        }
        return store[n-1];
    }
};