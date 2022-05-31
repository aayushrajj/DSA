class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long count = 0;
        int mod = 1e9 + 7;
        int n = deliciousness.size();
        if(n==1) return 0;
        unordered_map<int,int> map;
        for(auto i : deliciousness){
            
            for(int j=0;j<=21;j++){
                if( map.find( pow(2,j) - i) != map.end())
                    count += map[pow(2,j) - i] % mod;
            }
            
            map[i]++;
        }
        return count%mod;
    }
};