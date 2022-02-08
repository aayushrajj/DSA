class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int overallmax = 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        
        for(int i=1;i<n;i++){
            int maxpreviously = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxpreviously = max(maxpreviously,dp[j]);
                }
            }
            dp[i] = 1 + maxpreviously;
            overallmax = max(overallmax,dp[i]);
        }
        
        return overallmax;
    }
};