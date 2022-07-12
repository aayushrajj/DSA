class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size()-1;
        int first,last;
        first = last = -1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==nums[mid])
                first = mid , high = mid-1;
            else if(target<nums[mid])
                high = mid-1;
            else
                low = mid+1;
                
        }
        
        low =0;
        high =nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==nums[mid])
                last = mid , low = mid+1;
            else if(target<nums[mid])
                high = mid-1;
            else
                low = mid+1;
                
        }
         
        return {first,last};
    }
};