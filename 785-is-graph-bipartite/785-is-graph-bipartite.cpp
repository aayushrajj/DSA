class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
            if(color[i]!=0)
                continue;    
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
               
                for(auto &child : graph[node]){
                    if(color[child]==0){
                        color[child] = 3 - color[node];
                        q.push(child);
                    }
                    else if(color[child]==color[node])
                        return false;
                }
            }
        }
        
        return true;
    }
};