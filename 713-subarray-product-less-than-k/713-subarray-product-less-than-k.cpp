class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int product = 1;
        int left=0,right=0,count=0;
        while(right<n){
            if(product * nums[right] < k){
                product *= nums[right];
                count += right-left+1;
                right++;
            }
            else{
                if(left<right)
                    product /= nums[left];
                else
                    right++;
                left++;
            }
        }
        return count;
    }
};