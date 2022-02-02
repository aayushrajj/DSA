class Solution {
public:
    int dp[10001];
    int minCostClimbingStairs(vector<int>& cost) {
        int n =  cost.size();
        memset(dp,-1,sizeof(dp));
        return min( helper(cost,0) , helper(cost,1));
    }
    
    //helper function
    int helper(vector<int> &cost , int i){
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int stepOne = cost[i] + helper(cost,i+1);
        int stepTwo = cost[i] + helper(cost,i+2);
        
        return dp[i] = min(stepOne,stepTwo);
    }
};