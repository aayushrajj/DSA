class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int len = 0,startIdx=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    dp[i][j] = 1;
                else if(g==1)
                    dp[i][j] = s[i]==s[j] ? 1 : 0;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                        dp[i][j] = 1;
                }
                if(dp[i][j]==1){
                    len = g+1;
                    startIdx = i;
                }
            }
        }
        
        return s.substr(startIdx,len);
    }
};