class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currVec;
        int currSum = 0;
        sort(begin(candidates),end(candidates));
        backtrack(candidates,target,currVec,currSum,0);
        return res;
    }
    
    void backtrack(vector<int>& candidates,int target,vector<int> currVec,int currSum,int currIdx){
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
            backtrack(candidates,target,currVec,currSum,i+1);
            currSum -= candidates[i];
            currVec.pop_back();
        }
    }
};