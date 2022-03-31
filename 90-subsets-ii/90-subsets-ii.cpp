class Solution {
public:
    vector<vector<int>> allsubsets;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> empty;
        generate(empty,0,nums);
        return allsubsets;
    }
    
    void generate(vector<int> &subset,int i,vector<int> &nums){
        if(i==nums.size()){
            allsubsets.push_back(subset);
            return;
        }
        // include ith element
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        // backtrack
        subset.pop_back();
        //dont choose the current ith element [hence go to the next different number]
        int nextidx = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
        generate(subset,nextidx,nums);
    }
};