class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(i%2==0)
                res += nums[i];
        }
        return res;
    }
};