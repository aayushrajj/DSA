class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_set<int> map1;
        unordered_set<int> map2;
        for(auto v : nums1)
            map1.insert(v);
        for(auto v : nums2){
            map2.insert(v);
        }
        for(auto v : map1){
            if(map2.find(v)==map2.end())
                answer[0].push_back(v);
        }
        for(auto v : map2){
            if(map1.find(v)==map1.end())
                answer[1].push_back(v);
        }
        return answer;
    }
};