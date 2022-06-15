class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0,hi=n-1;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]>target)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return nums[lo] < target ? lo+1 : lo;
    }
};