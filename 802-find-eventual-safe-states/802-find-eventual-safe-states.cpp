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
        visited[node] = 1;
        
        for(auto &v : graph[node]){
            if(visited[v]==1)
                return false;
            if(visited[v]==0){
                if(!dfs(graph,visited,v))
                    return false;
            }
        }
        visited[node] = 2;
        return true;
    }
};