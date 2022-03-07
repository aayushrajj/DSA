class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int size = words[i].size();
            int j=0,pos=0;
            while(j<size){
                auto ix = s.find(words[i][j],pos);
                if(ix==string::npos) break;
                pos = ix+1;
                j++;
            }
            if(j==size)
                ans++;
        }
        return ans;
    }
};