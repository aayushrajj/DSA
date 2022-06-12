class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size();
        sort(beans.begin(),beans.end());
        
        vector<long long> prefixSum(n);
        prefixSum[0] = beans[0];
        for(long long i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + beans[i]; 
        }
        
        long long res = LONG_MAX;
        for(long long i=0;i<n;i++){
            long long curr = 0;
            if(i==0){
                curr = ( prefixSum[n-1]-prefixSum[i] ) - ( (n-1-i)*beans[i] );
            }
            else{
                curr = ( prefixSum[n-1]-prefixSum[i] ) - ( (n-1-i)*beans[i] ) + prefixSum[i-1];
            }
            res = min(res,curr);
        }
        return res;
    }
};