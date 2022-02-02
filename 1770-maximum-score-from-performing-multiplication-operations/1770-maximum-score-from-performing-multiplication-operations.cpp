class Solution {
public:
    int dp[1000][1000];
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(); 
        memset(dp,-1,sizeof(dp));
        int left =0 , right = n-1;
        int i = 0;
        return helper(nums,multipliers,i,left,right);
    }
    
    //helper function
    int helper(vector<int>& nums,vector<int>& multipliers,int i,int left,int right){
        if(i==multipliers.size())
            return 0;
        if(dp[left][i]!=-1)
            return dp[left][i];
        
        int chooseleft = nums[left]*multipliers[i] + helper(nums,multipliers,i+1,left+1,right);
        int chooseright = nums[right]*multipliers[i] + helper(nums,multipliers,i+1,left,right-1);
        
        return dp[left][i] = max(chooseleft,chooseright);
    }
};