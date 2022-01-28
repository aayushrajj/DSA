class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        unordered_set<char> visited;
        int start = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(visited.find(s[i])==visited.end()){
                visited.insert(s[i]);
                len = max(len,i-start+1);
            }
            else{
                while(start!=i && s[start]!=s[i]){
                    visited.erase(s[start++]);
                }
                start++;
                len = max(len,i-start+1);
            }
        }
        return len;
    }
};