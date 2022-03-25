class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum=0;
        for(auto &num : nums)
            sum += num;
        if(sum&1)
            return false;
        int target = sum/2;
        vector<vector<int>> dp(size+1,vector<int> (target+1,-1));
        return subset(nums,size,target,dp);
    }
    
    bool subset(vector<int>& nums,int n,int sum,vector<vector<int>>& dp){
        if(sum==0)
            return 1;
        if(n<=0)
            return 0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(nums[n-1]>sum)
            return dp[n][sum] = subset(nums,n-1,sum,dp);
        else
            return dp[n][sum] = subset(nums,n-1,sum,dp) || subset(nums,n-1,sum-nums[n-1],dp);
    }
};