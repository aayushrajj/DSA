class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int i=0,j=0;
        int maxlen=0;
        unordered_set<char> map;
        while(j<n){
            if(map.find(s[j])==map.end()){
                map.insert(s[j]);
                maxlen = max(maxlen,j-i+1);
                j++;
            }
            else{
                map.erase(s[i]);
                i++;
            }
        }
        return maxlen;
    }
};