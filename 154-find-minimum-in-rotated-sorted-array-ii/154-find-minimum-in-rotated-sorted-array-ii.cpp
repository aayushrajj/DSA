class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo=0,hi=n-1;
        int val = INT_MAX;
        while(lo<=hi){ 
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo = mid+1;
            else if(nums[mid]<nums[hi])
                hi = mid;
            else
                hi--;
        }
        
        return nums[lo];
    }
};