// given : eggs = k , floors = n
class Solution {
public:
    int dp[105][10005];
    int superEggDrop(int eggs, int floors) {
        if(eggs==0)
            return 0;
        if(eggs==1)
            return floors;
        memset(dp,-1,sizeof(dp));
        return solve(eggs,floors);
    }
    
    int solve(int e , int f){
        if(f<=1)
            return dp[e][f] = f;
        if(e==1)
            return dp[e][f] = f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];
        
        int minans = INT_MAX;
        int left = 1 , right = f;
        while(left<=right){
            int mid = left + (right-left)/2;
            int down = 0 , up = 0;
            if(dp[e-1][mid-1]!=-1)
                down = dp[e-1][mid-1];
            else
                down = solve(e-1,mid-1);
            if(dp[e][f-mid]!=-1)
                up = dp[e][f-mid];
            else
                up = solve(e,f-mid);
            int temp = 1 + max( down , up );
            minans = min(minans,temp);
            if(down<up)
                left = mid+1;
            else
                right = mid-1;
        }
        return dp[e][f] = minans;
    }
};