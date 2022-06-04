class Solution {
public:
    //bottom up
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res , dfs(manager,informTime,i));
        }
        return res;
    }
    
    int dfs(vector<int> &manager , vector<int>& informTime , int node){
        if(manager[node]!=-1){
            informTime[node] += dfs(manager , informTime , manager[node]);
            manager[node] = -1;
        }
        return informTime[node];
    }
};