class Solution {
public:
    int getMaximumGenerated(int n) {
        int maxvalue =0;
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++){
            if(i==0||i==1){
                dp[i]=i;
            }
            else if(i%2==0){
                dp[i] = dp[i/2];
            }
            else{
                dp[i] = dp[i/2]+dp[(i/2)+1];
            }
            maxvalue = max(maxvalue,dp[i]);
        }
        return maxvalue;
    }
};