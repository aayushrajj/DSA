class Solution {
public:
    int numSub(string s) {
        int i=0,j=0;
        long long count=0;
        int mod = 1e9 + 7;
        while(j<s.length()){
            if(s[j]=='0'){
                long long n = j-i;
                count += n*(n+1)/2;
                j++;
                i = j;
            }
            else{
                j++;
            }
        }
        int n = j-i;
        count += n*(n+1)/2;
        count %= mod;
        return count;
    }
};