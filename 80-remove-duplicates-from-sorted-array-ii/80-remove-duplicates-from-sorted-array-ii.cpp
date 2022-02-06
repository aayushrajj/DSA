class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int i = 1 , j =1;
        int count = 1;
        while(j<n){
            if(nums[j]!=nums[j-1]){
                count = 1;
                nums[i] = nums[j];
                i++;
            }
            else{
                if(count<2){
                    nums[i] = nums[j];
                    i++;
                    count++;
                }
            }
            j++;
        }
        return i;
    }
};