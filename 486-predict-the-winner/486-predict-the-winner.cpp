class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        int left = 0 , right = n-1;
        return helper(nums,left,right,dp) >= 0;
    }
    
    //helper dp function
    int helper(vector<int>& nums,int left,int right,vector<vector<int>> &dp){
        if(left==right){
            return dp[left][right] = nums[left];
        }
        if(dp[left][right]!=0)
            return dp[left][right];
        
        int chooseleft = nums[left] - helper(nums,left+1,right,dp);
        int chooseright = nums[right] - helper(nums,left,right-1,dp);
        
        return dp[left][right] = max(chooseleft,chooseright);
     }
};