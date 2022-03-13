class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> visited;
        int start=0, end=0;
        int length=0;
        while(end<n){
            if(visited.find(s[end])==visited.end()){
                visited.insert(s[end]);
                length = max(length,end-start+1);
                end++;
            }
            else{
                visited.erase(s[start]);
                start++;
            }
        }
        return length;
    }
};