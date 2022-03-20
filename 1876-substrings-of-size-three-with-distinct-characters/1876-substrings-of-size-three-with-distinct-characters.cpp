class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int count=0;
        for(int i=1;i<n-1;i++){
            set<char> store = {s[i-1],s[i],s[i+1]};
            if(store.size()==3)
                count++;
        }
        return count;
    }
};