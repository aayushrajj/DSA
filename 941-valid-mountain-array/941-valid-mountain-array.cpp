class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        
        bool up = false;
        bool down = false;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
                return false;
            
            if(nums[i] > nums[i-1]){
                if(down)
                    return false;
                up = true;
            }
            
            if(nums[i-1] > nums[i])
                down = true;
        }
        
        return up && down;
    }
};