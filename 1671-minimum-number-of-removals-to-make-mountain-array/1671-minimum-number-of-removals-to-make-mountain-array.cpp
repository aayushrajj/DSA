class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        vector<int> dp;
        for(int i=0;i<n;i++){
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it != dp.end())
                *it = nums[i];
            else
                dp.push_back(nums[i]);
            left[i] = dp.size();
        }
        
        dp.clear();
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it != dp.end())
                *it = nums[i];
            else
                dp.push_back(nums[i]);
            right[i] = dp.size();
        }
        
        reverse(right.begin(),right.end());
        
        int result = 0;
        for (int i=0;i<n;i++)
        {
            if (left[i] != 1 && right[i] != 1){
                // int x = n - (left[i]+right[i]-1);
                // ans = min(ans, x);
                result = max(result, left[i] + right[i]-1);
            }
                 
        }
        return n - result;
        // return ans;
    }
};