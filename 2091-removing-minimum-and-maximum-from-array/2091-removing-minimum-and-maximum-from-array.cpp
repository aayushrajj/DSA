class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int maxv=INT_MIN,minv=INT_MAX;
        int leftmax =0 , leftmin=0;
        int rightmax=0 , rightmin=0;
        for(int i=0;i<n;i++){
            if(maxv<nums[i]){
                maxv = nums[i];
                leftmax = i+1;
                rightmax = n-i;
            }
            if(minv>nums[i]){
                minv = nums[i];
                leftmin = i+1;
                rightmin = n-i;
            }
        }
        int finalleft = max(leftmin,leftmax);
        int finalright = max(rightmin,rightmax);
        int finalboth = min(leftmax,rightmax)+min(leftmin,rightmin);
        return min(finalleft,min(finalright,finalboth));
    }
};