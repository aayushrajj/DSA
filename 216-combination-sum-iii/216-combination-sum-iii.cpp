class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currVec;
        backtrack(n,k,currVec,1);
        return res;
    }
    
    void backtrack(int n,int k,vector<int> currVec,int currIdx){
        if(currVec.size()==k){
            if(n==0)
                res.push_back(currVec);
            return;
        }
        for(int i=currIdx;i<=9;i++){
            currVec.push_back(i);
            backtrack(n-i,k,currVec,i+1);
            currVec.pop_back();
        }     
    }
    
};