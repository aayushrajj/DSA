class Solution {
public:
    int numSub(string s) {
        int i=0;
        long res=0;
        int mod = 1e9 + 7;
        while(i<s.length()){
            long count =0;
            while(s[i]=='1')
                count++ , i++;
            res += count*(count+1)/2;
            i++;
        }
        res %= mod;
        return res;
    }
};