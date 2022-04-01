class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<vector<int>> res{{}};
        int size =0 , startidx =0;
        for(int i=0;i<n;i++){
            startidx = i>=1 && nums[i]==nums[i-1] ? size : 0;
            size = res.size();
            for(int j=startidx;j<size;j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;

    }
};