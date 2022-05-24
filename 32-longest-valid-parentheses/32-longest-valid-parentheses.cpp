class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int maxlen = 0;
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    if(i>=2)
                        dp[i] = dp[i-2]+2;
                    else
                        dp[i] = 2;
                }
                else if(i-dp[i-1]>0 && s[i-1-dp[i-1] ]=='('){
                    if(i-dp[i-1]>=2)
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    else
                        dp[i] = dp[i-1] + 2;
                }
                maxlen = max(maxlen,dp[i]);
            }
        }
        return maxlen;
    }
};