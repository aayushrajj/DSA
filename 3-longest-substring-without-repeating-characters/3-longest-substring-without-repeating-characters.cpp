class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> visited;
        int start=0, end=0;
        int length=0;
        while(end<n){
            if(visited.find(s[end])==visited.end()){
                visited.insert(s[end]);
                length = max(length,end-start+1);
                end++;
            }
            else{
                while(start<end){
                    visited.erase(s[start]);
                    if(s[start]==s[end])
                        break;
                    start++;
                }
                start++;
                visited.insert(s[end]);
                // length = max(length,end-start+1);
                end++;
                
            }
        }
        return length;
    }
};