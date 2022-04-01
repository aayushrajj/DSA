class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currVec;
        int currSum = 0;
        backtrack(candidates,target,currSum,currVec,0);
        return res;
    }
    
    void backtrack(vector<int>& candidates,int target,int currSum,vector<int> currVec,int currIdx){
        if(currSum>target)
            return;
        if(currSum==target){
            res.push_back(currVec);
            return;
        }
        
        for(int i=currIdx;i<candidates.size();i++){
            currVec.push_back(candidates[i]);
            currSum += candidates[i];
            backtrack(candidates,target,currSum,currVec,i);
            currSum -= candidates[i];
            currVec.pop_back();
        }
    }
};