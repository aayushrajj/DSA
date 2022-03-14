class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int move=0;
        int i=0,j=1;
        while(j<n){
            if(nums[j]>nums[i]){
                i++; j++;
            }
            else{
                int diff = abs(nums[j]-nums[i]) + 1;
                move += diff;
                nums[j] = nums[j]+diff;
                i++; j++;
            }
        }
        return move;
    }
};