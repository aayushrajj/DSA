class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> visited(n+1);
        for(auto &e : edges){
            
            fill(visited.begin(),visited.end(),0);
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            
            if(isCycle(graph,visited,e[0],0))
                return e;
        }
        
        return {};
    }
    
    bool isCycle(vector<vector<int>> &graph , vector<bool> &visited , int currNode , int parent){
        if(visited[currNode])
            return true;
        
        visited[currNode] = true;
        for(auto &child : graph[currNode]){
            if(child!=parent && isCycle(graph,visited,child,currNode))
                return true;
        }
        
        return false;
    }
};