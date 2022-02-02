class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> shash(26,0);
        vector<int> thash(26,0);
        if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();i++){
            shash[s[i]-'a']++;
            thash[t[i]-'a']++;
        }
        
        return shash==thash;
    }
};