class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        for(int i=0;i<k+1;i++){    
            vector<int> temp;
            temp = dist;
            for(auto &f : flights){
                int u = f[0];
                int v = f[1];
                int cost = f[2];
                if(dist[u]!=INT_MAX && temp[v] > dist[u] + cost){
                    temp[v] = dist[u] + cost;
                }
            }
            dist = temp;
        }
        
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};