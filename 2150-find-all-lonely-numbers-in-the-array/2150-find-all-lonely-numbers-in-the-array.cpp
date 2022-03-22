class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map[nums[i]]==1 && map.find(nums[i]+1)==map.end() &&
               map.find(nums[i]-1)==map.end()){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};