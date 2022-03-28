class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string,int> map;
        stringstream combine;
        combine << s1 << " " << s2;
        string words;
        while(combine>>words)
            map[words]++;
        for(auto it : map){
            if(it.second==1)
                res.push_back(it.first);
        }
        return res;
    }
};