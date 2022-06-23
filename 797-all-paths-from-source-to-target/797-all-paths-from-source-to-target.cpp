class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> currVec;
        currVec.push_back(0);
        dfs(graph,currVec,n,0);
        return res;
    }
    
    void dfs(vector<vector<int>>& graph,vector<int> currVec,int &n,int node){
        if(node==n-1){
            res.push_back(currVec);
            return;
        }
        
        for(auto &v : graph[node]){
            currVec.push_back(v);
            dfs(graph,currVec,n,v);
            currVec.pop_back();
        }
    }
};