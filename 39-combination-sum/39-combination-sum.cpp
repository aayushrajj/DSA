class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currComb;
        int currIndex=0;
        int currSum=0;
        combinations(candidates,target,currComb,currSum,currIndex);
        return ans;
    }
    
    void combinations(vector<int> &candidates,int target,vector<int> currComb,int currSum,int currIndex){
        if(currSum > target)
            return;
        if(currSum==target){
            ans.push_back(currComb);
            return;
        }
        
        for(int i=currIndex;i<candidates.size();i++){
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            combinations(candidates,target,currComb,currSum,i);
            currComb.pop_back();
            currSum -= candidates[i];
        }
    }

};