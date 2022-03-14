class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums)
            total += num;
        int prefixsum=0;
        for(int i=0;i<n;i++){
            if(prefixsum*2==total-nums[i])
                return i;
            prefixsum += nums[i];
        }
        return -1;
    }
};