class Solution {
public:
    #define MOD 1e9+7
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long int> map;
        
        sort(arr.begin(),arr.end());
        for(auto &a : arr){
            map.insert({a,1});
        }
        
        for(int i=1;i<arr.size();i++){
            long long int count = 0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(map.find(arr[i]/arr[j])!=map.end()){
                        count += map.find(arr[j])->second * map.find(arr[i]/arr[j])->second;
                    }
                }
            }
            map.find(arr[i])->second += count;
        }
        
        long long int sum = 0;
        for(auto it : map){
            sum += it.second;
        }
        
        return sum%1000000007;
    }
};