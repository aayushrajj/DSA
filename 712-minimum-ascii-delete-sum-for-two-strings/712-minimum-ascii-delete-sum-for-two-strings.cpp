class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp = vector<vector<int>> (m+1,vector<int> (n+1,0));
        
        for(int i=1;i<m+1;i++){
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
        }
        for(int j=1;j<n+1;j++){
            dp[0][j] = dp[0][j-1] + (int)s2[j-1];
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min( (int)s1[i-1] + dp[i-1][j] , 
                                    (int)s2[j-1] + dp[i][j-1]);
            }
        }
        
        return dp[m][n];

    }
};