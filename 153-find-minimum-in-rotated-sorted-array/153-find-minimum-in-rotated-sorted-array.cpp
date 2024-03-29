class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo=0,hi=n-1;
                

        while(lo<=hi){
            if(nums[lo] <= nums[hi])
                return nums[lo];
            
            int mid = lo+(hi-lo)/2;
            
            if(nums[mid] >= nums[lo])
                lo = mid+1;
            else
                hi = mid;
        }
        
        return -1;
    }
};