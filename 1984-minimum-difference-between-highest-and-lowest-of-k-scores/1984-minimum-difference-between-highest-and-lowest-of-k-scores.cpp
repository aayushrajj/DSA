class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0) return 0;
        int diff=INT_MAX;
        for(int i=k-1;i<n;i++){
            diff = min(diff,nums[i]-nums[i-k+1]);
        }
        return diff==INT_MAX ? 0 : diff;
    }
};