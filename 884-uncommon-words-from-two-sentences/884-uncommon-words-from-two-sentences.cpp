class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string,int> map;
        string word = "";
        for(auto v : s1){
            if(v==' '){
                map[word]++;
                word = "";
            }
            else
                word += v;
        }
        map[word]++;
        word = "";
        for(auto v : s2){
            if(v==' '){
                map[word]++;
                word = "";
            }
            else
                word += v;
        }
        map[word]++;
        for(auto i : map)
            if(i.second==1) res.push_back(i.first);
        return res;
    }
};