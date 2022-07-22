class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int last = nums[0];
        int total=0;
        
        for(int i=1;i<n-1;i++){
            if(nums[i]==last){
                last = nums[i];
                continue;
            }
            
            if(nums[i]>last && nums[i]>nums[i+1])
                total++ , last = nums[i];
            else if(nums[i]<last && nums[i]<nums[i+1])
                total++ , last = nums[i];
            
        }
        
        return total;
    }
};