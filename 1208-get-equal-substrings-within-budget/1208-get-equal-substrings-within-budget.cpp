class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int m = t.length();
        int i=0,j=0,maxlen=0,prediff=0;
        while(j<n){
            prediff += abs( (s[j]-'a')-(t[j]-'a') );
            while(prediff>maxCost){
                prediff -= abs( (s[i]-'a')-(t[i]-'a') );
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;  
        }
        return maxlen;
    }
};