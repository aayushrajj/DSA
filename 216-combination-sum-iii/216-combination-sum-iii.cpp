class Solution {
public:
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currVec;
        backtrack(n,k,currVec,0);
        return res;
    }
    
    void backtrack(int n,int k,vector<int> currVec,int currIdx){
        if(currVec.size()==k && n==0){
            res.push_back(currVec);
            return;
        }
        if(currVec.size()>=k)
            return;
        for(int i=currIdx;i<9;i++){
            if(arr[i]>n)
                break;
            currVec.push_back(arr[i]);
            backtrack(n-arr[i],k,currVec,i+1);
            currVec.pop_back();
        }     
    }
    
};