class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==1 &&nums[0] == val || n<1) return 0;
        int i = 0 , j = 0;
        while(j<n){
            if(nums[j]!=val){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};