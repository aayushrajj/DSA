class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> visited(n,0);
        
        for(int i=0;i<n;i++){
            if(dfs(graph,visited,i))
                res.push_back(i);
        }
        
        return res;
    }
    
    bool dfs(vector<vector<int>>& graph,vector<int> &visited,int node){
        if(visited[node])
            return visited[node]==1; // is not fully explored but visited then false
        
        visited[node] = -1;
        
        for(auto &v : graph[node]){
            if(!dfs(graph,visited,v))
                return false;
        }
        visited[node] = 1; //fully explored
        return true;
    }
};