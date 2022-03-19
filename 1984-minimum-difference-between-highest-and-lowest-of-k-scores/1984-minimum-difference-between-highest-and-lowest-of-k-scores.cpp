class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff=INT_MAX;
        for(int i=0;i<=n-k;i++){
            diff = min(diff,nums[i+k-1]-nums[i]);
        }
        return diff==INT_MAX ? 0 : diff;
    }
};