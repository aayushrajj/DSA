class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        int i = 0 , j = n-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==k){
                count++;
                i++;
                j--;
            }
            else if(sum>k)
                j--;
            else
                i++;
        }
        return count;
    }
};