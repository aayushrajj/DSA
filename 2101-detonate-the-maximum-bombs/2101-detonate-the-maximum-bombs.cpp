class Solution {
public:
    #define ll long long
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                    adj[i].push_back(j);
                }  
            }
        }
        
        int maxBomb=0;
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            int curr = dfs(adj,visited,i);
            maxBomb = max(maxBomb,curr);
        }
        
        return maxBomb;
    }
    
    bool check(ll x1,ll y1,ll x2,ll y2,ll radius){
        ll currRange = abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2);
        return currRange<=radius*radius;
    }
    
    int dfs(vector<vector<int>> &adj,vector<int> &visited,int node){
        int count = 1;
        visited[node] = 1;
        
        for(auto &child : adj[node]){
            if(!visited[child])
                count += dfs(adj,visited,child);
        }
        
        return count;
    }
};