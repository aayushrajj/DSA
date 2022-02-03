class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapp;
        for(auto& s : strs){
            string t = s;
            sort(t.begin(),t.end());
            mapp[t].push_back(s);
        }
        
        for(auto& e : mapp){
            ans.push_back(e.second);
        }
        
        return ans;
    }
};