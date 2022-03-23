class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long long> map;
        long long left=0,right=0;
        while(right<n){
            if(right-left>k){
                map.erase(nums[left]);
                left++;
            }
            auto it = map.lower_bound((long long)nums[right]-t);
            if(it!=map.end() && *it-nums[right]<=t)
                return true;
            map.insert(nums[right]);
            right++;
        }
        return false;
    }
};