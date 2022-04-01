class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        backtrack(vector<int>(),1,n,k,res);
        return res;
    }
    
    void backtrack(vector<int> comb,int curr,int n,int k,vector<vector<int>> &res){
        if(k==0){
            res.push_back(comb);
            return;
        }
        //not include
        if(curr<=n-k) backtrack(comb,curr+1,n,k,res);
        //include
        comb.push_back(curr);
        backtrack(comb,curr+1,n,k-1,res); 
    }
};