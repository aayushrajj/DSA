class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size();
        long long res = LONG_MAX;
        sort(beans.begin(),beans.end());
        
        long long sum = accumulate(beans.begin(),beans.end(),0L);
        
        for(long long i=0;i<n;i++)
            res = min(res , sum - (n-i)*beans[i] );
        
        return res;
    }
};