class Solution {
public:
    
    // Using Dijkstra's Alogorithm here.
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});  // to_city , cost . 
        }
        
        vector<int> dist(n+1,INT_MAX);
        dist[src] = 0;
        
        queue<pair<int, pair<int,int>>>pq;
        
        pq.push({0,{src,0}});  // cost , previous_node , stops.
        
        while(!pq.empty()){
            int diss = pq.front().first;
            int prev = pq.front().second.first;
            int stps = pq.front().second.second;
            
            pq.pop();
            
            for(auto it:adj[prev]){
                int nextNode = it.first;
                int nextDist = it.second;
                
                if(dist[nextNode] > diss+nextDist && stps<=k){
                    dist[nextNode] = diss+nextDist;
                    pq.push({dist[nextNode],{nextNode,stps+1}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
        
    }
};