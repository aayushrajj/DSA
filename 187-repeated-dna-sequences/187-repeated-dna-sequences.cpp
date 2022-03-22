class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int> map;
        vector<string> res;
        for(int i=0;i<n-9;i++){
            map[s.substr(i,10)]++;
        }
        for(auto key : map){
            if(key.second>1)
                res.push_back(key.first);
        }
        return res;
    }
};