class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int n = s.length();
        int m = t.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    dp[i][j] = (j==0) ? 1:0;
                else{
                    if(s[i-1]==t[j-1])
                        dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j] ) % mod;
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};