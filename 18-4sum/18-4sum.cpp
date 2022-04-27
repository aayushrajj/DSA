class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1])
                    continue;
                int low = j+1;
                int high = n-1;
                while(low<high){
                    int sub_target = target - nums[i] - nums[j];
                    int sum = nums[low] + nums[high];
                    // ll sum = (ll)nums[i]+(ll)nums[j]+(ll)nums[low]+(ll)nums[high];
                    if(sub_target==sum){
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        while(low<high && nums[low]==nums[low-1])
                            low++;
                    }
                    else if(sum < sub_target)
                        low++;
                    else
                        high--;
                }
            }
        }
        return res;
    }
};