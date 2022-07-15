class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());
        
        unordered_map<int,int> rankMap;
        for(int i=0;i<n;i++){
            rankMap.emplace( copy[i] , rankMap.size() + 1 );
            
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = rankMap[arr[i]];
        }
        
        return res;
    }
};