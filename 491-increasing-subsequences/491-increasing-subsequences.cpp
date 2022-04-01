class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res{{}};
        set<vector<int>> hash;
        for(int i=0;i<nums.size();i++){
            int n = res.size();
            for(int j=0;j<n;j++){
                if(res[j].empty() || nums[i]>=res[j].back()){
                    res.push_back(res[j]);
                    if(res.back().size()>1) hash.insert(res.back());
                    res.back().push_back(nums[i]);
                    if(res.back().size()>1) hash.insert(res.back());
                }
            }
        }
        return vector<vector<int>>(hash.begin(),hash.end());
    }
};