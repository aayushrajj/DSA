class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalsum = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum>=0){
                sum += nums[i];
            }
            else
                sum = nums[i];
            globalsum = max(globalsum,sum);
        }
        return globalsum;
    }
};