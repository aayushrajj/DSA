class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(target==nums[mid])
                return true;
            if(nums[lo]<nums[mid]){
                if(target>=nums[lo] && target<nums[mid])
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            else if(nums[lo]>nums[mid]){
                if(target>nums[mid] && target<=nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;   
            }
            else
                lo++;
        }
        return false;
    }
};