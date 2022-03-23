class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> map;
        int left=0,right=0;
        while(right<n){
            if(right-left>k){
                map.erase(nums[left]);
                left++;
            }
            auto val = map.insert(nums[right]);
            if(val.second==false)
                return true;
            right++;
        }
        return false;
    }
};