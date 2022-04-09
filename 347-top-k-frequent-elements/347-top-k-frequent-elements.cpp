class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<vector<int>> store;
        for(auto v : map){
            store.push_back({v.second,v.first});
        }
        sort(store.begin(),store.end());
        int j=store.size()-1;
        while(k--){
            res.push_back(store[j][1]);
            j--;
        }
        return res;
    }
};