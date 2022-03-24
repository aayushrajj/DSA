class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26,0);
        int left=0,maxlen=0,maxcount=0;
        for(int i=0;i<n;i++){
            count[s[i]-'A']++;
            maxcount = max(maxcount,count[s[i]-'A']);
            if(i-left+1 - maxcount > k){
                count[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,i-left+1);
        }
        return maxlen;
    }
};