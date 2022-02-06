class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int i,j;
        for(i=2,j=2;i<n;i++){
            if(nums[j-2]!=nums[i]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};