class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            curr = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    curr += 1;
                }
                else break;
            }
            ans = max(curr,ans);
        }
        
        return ans;
    }
};