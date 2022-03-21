class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
    
    int helper(vector<int> &nums , int k){
        int n = nums.size();
        int total=0,j=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map.size()>k){
                while(map.size()>k){
                    map[nums[j]]--;
                    if(map[nums[j]]==0)
                        map.erase(nums[j]);
                    j++;
                }
            }
            total += i-j+1;
        }
        return total;
    }
};