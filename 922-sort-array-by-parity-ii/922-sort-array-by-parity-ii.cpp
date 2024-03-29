class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i=0,j=1;i<n;){
            if(nums[i]%2==0)
                i += 2;
            else if(nums[j]%2!=0)
                j += 2;
            else
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};