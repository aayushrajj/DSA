class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans=0,maxval=0;
        
        for(auto n : nums){
            maxval = max(n,maxval);
        }
        
        vector<vector<int>> dp(2*maxval+1,vector<int>(n,0));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j]+maxval;
                dp[diff][i] = dp[diff][j] + 1;
                ans = max(ans,dp[diff][i]);
            }
        }
        
        return ans+1;
    }
};