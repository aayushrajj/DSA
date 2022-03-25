class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
    
    int helper(vector<int> &nums , int k){
        int n = nums.size();
        int left=0,res=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1)
                count++;
            while(count>k){
                if(nums[left]&1)
                    count--;
                left++;
            }
            res += i-left+1;
        }
        return res;
    }
};