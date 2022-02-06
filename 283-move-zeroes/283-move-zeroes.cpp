class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        while(i<n){
            if(nums[i]==0)
                break;
            i++;
        }
        j = i+1;
        while(j<n){
            if(nums[j]!=0){
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
            j++;
        }
    }
};