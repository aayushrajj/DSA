class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> dp;
//         dp.push_back(nums[0]);
//         for(int i=1;i<n;i++){
//             if(nums[i]>dp.back())
//                 dp.push_back(nums[i]);
//             else{
//                 int k = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
//                 dp[k] = nums[i];
//             }
//         }
//         int len1 = dp.size();
        
//         dp.clear();
//         reverse(nums.begin(),nums.end());
//         dp.push_back(nums[0]);
//         for(int i=1;i<n;i++){
//             if(nums[i]>dp.back())
//                 dp.push_back(nums[i]);
//             else{
//                 int k = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
//                 dp[k] = nums[i];
//             }
//         }
//         int len2 = dp.size();
        
//         int mountainSub = len1+len2-1;
        
//         return n-mountainSub;
        
            int n=nums.size();
       vector<int> left(n);
        vector<int> right(n);
        int result=0;
        for (int i=1;i<n;i++)
        {
           for (int j=0;j<i;j++)
           {
               if (nums[i]>nums[j])
               left[i]=max(left[i], left[j]+1);
           }
                                     
        }
            
        for (int i=n-2; i>-1;i--)
        {
           for (int j=n-1;j>i;j--)
           {
             
                if (nums[i]>nums[j])
                right[i]=max(right[i],right[j]+1);
               
           }
         
        }
        for (int i=1;i<n;i++)
        {
            if (left[i] != 0 && right[i] != 0)
                result = max(result, left[i] +right[i]); 
        }
        return n - result -1;
    }
};