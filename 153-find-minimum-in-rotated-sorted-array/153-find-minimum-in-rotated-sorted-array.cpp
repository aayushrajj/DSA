class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo=0,hi=n-1;
        
        if(nums[lo] <= nums[hi])
            return nums[lo];
        

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid-1] > nums[mid])
                return nums[mid];
            
            if(nums[mid] > nums[lo])
                lo = mid+1;
            else
                hi = mid-1;
        }
        
        return -1;
    }
};