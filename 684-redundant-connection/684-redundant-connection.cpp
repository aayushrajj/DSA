class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1,0);
        vector<int> graph[n+1];
        
        for(auto &e : edges){
            indegree[e[0]]++;
            indegree[e[1]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n+1;i++){
            if(indegree[i]==1)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &v : graph[curr]){
                indegree[v]--;
                if(indegree[v]==1)
                    q.push(v);
            }
        }
        
        unordered_set<int> store;
        for(int i=0;i<n+1;i++){
            if(indegree[i]>1)
                store.insert(i);
        }
        
        vector<int> res;
        for(auto &e : edges){
            if(store.find(e[0]) != store.end() && store.find(e[1]) != store.end()){
                res.clear();
                res.push_back(e[0]);
                res.push_back(e[1]);
            }
        }
        
        return res;
    }
};