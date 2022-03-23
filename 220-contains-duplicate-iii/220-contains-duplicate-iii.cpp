class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long long> map;
        for(int i=0;i<n;i++){
            if(i>k)
                map.erase(nums[i-k-1]);
            auto it = map.lower_bound((long long)nums[i]-t);
            if(it!=map.end() && *it-nums[i]<=t)
                return true;
            map.insert(nums[i]);
        }
        return false;
    }
};