class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        set<pair<int,int>> map;
        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += mat[i][j];
            }
            map.insert({sum,i});
        }
        vector<int> res;
        auto it = map.begin();
        while(k--){
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};