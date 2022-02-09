class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int total = 0;
        int i=0,j=1;
        while(i<n && j<n){
            if(nums[i]+k<nums[j])
                i++;
            else if(i==j || nums[i]+k>nums[j])
                j++;
            else{
                i++;
                total++;
                while(i<n && nums[i]==nums[i-1])
                    i++;
            }
        }
        return total;
    }
};