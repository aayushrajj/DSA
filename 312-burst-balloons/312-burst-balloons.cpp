class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int res = solve(dp,nums,1,n-1);
        return res;
    }
    
    int solve(vector<vector<int>> &dp,vector<int> &nums,int i,int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int maxans = INT_MIN;
        for(int k=i;k<=j-1;k++){
            int temp = solve(dp,nums,i,k) + solve(dp,nums,k+1,j) + nums[i-1]*nums[k]*nums[j];
            maxans = max(maxans,temp);
        }
        return dp[i][j] = maxans;
    }
};