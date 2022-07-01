class Solution {
public:
    // DFS
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        
        for(auto &d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        
        vector<int> color(n+1,0);
        vector<int> visited(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                color[i] = 1;
                if(!dfs(graph,visited,color,i))
                    return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<int> graph[],vector<int> &visited,vector<int> &color,int node){
        visited[node] = 1;
        for(auto &v : graph[node]){
            if(!visited[v]){
                color[v] = 3-color[node];
                if(!dfs(graph,visited,color,v))
                    return false;
            }
            else if(color[v]==color[node])
                return false;
        }   
        return true;
    }
};