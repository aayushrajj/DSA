class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(nums[mid]==target)
                return mid;
            //left part is sorted
            if(nums[lo] <= nums[mid]){
                if(target>=nums[lo] && target<nums[mid])
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            // right part is sorted
            else{
                if(target>nums[mid] && target<=nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return -1;
    }
};