class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        long long left=0,right=0,total=0;
        long long maxlen=0;
        while(right<n){
            total += nums[right];
            while(nums[right]*(right-left+1) - total > k){
                total -= nums[left];
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};