class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> one;
        unordered_set<int> two;
        
        unordered_set<int> res;
        for(auto &n : nums1)
            one.insert(n);
        for(auto &n : nums2)
            two.insert(n);
        
        for(auto &n : nums2)
            if(one.find(n) != one.end())
                res.insert(n);
        
        for(auto &n : nums3){
            if(one.find(n) != one.end())
                res.insert(n);
            if(two.find(n) != two.end())
                res.insert(n);
        }
        
        vector<int> ans;
        for (auto it = res.begin(); it != res.end(); ++it)
            ans.push_back(*it);
        
        return ans;
    }
};