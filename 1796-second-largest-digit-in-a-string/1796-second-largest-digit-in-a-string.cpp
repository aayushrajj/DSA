class Solution {
public:
    int secondHighest(string s) {
        int n = s.length();
        set<int> pq;
        for(int i=0;i<n;i++){
            if(s[i]>=48 && s[i]<=57)
                pq.insert(s[i]-'0');
        }
        
        if(pq.size()<=1)
            return -1;
        auto it = pq.end();
        it--; it--;
        return *it;
    }
};