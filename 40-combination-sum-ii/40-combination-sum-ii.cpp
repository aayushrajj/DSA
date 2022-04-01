class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currVec;
        int currSum=0;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,currSum,currVec,0);
        return res;
    }
    
    void helper(vector<int> &candidates,int target,int currSum,vector<int> &currVec,int currIdx){
        if(currSum>target)
            return;
        if(currSum==target){
            res.push_back(currVec);
            return;
        }
        for(int i=currIdx;i<candidates.size();i++){
            if(i>currIdx && candidates[i]==candidates[i-1])
                continue;
            currVec.push_back(candidates[i]);
            currSum += candidates[i];
            helper(candidates,target,currSum,currVec,i+1);
            currSum -= candidates[i];
            currVec.pop_back();
        }
    }
};