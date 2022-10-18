class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res =0;
        int start =0 , end =0;
        int window = 0;
        
        while(end < nums.size()){
            if(nums[end] >= left && nums[end] <= right){
                window = end-start+1;
            }
            else if(nums[end] > right){
                window = 0;
                start = end+1;
            }
            // else if(nums[end] < left){
            //     window = window;
            // }
            
            res += window;
            end++;
        }
        
        return res;
    }
};