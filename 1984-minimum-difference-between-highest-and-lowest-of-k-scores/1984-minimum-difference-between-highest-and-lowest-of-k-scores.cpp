class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0) return 0;
        int diff=INT_MAX;
        for(int i=0;i<n-k+1;i++){
            diff = min(diff,abs(nums[i+k-1]-nums[i]));
        }
        return diff==INT_MAX ? 0 : diff;
    }
};