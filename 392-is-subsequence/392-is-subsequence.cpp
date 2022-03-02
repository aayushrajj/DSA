class Solution {
public:
    bool isSubsequence(string s, string t) {
        int end=0;
        for(int i=0;i<t.length();i++){
            if(s[end]==t[i])
                end++;
        }
        return end==s.length();
    }
};