class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask=0 , res =0;
        int low = 0;
        
        for(int i=0;i<nums.size();i++){
            while( (mask & nums[i]) !=0)
                mask ^= nums[low++];
            
            mask |= nums[i];
            
            res = max(res , i-low+1);
        }
        
        return res;
    }
};