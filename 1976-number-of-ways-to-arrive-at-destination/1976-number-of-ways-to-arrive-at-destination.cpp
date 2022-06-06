#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        int mod = 1e9 + 7;
        
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            graph[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        
        vector<ll> dist(n,LONG_MAX);
        vector<ll> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pll , vector<pll> , greater<pll>> pq;
        pq.push({0,0}); // {time,v}
        
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [time,v] : graph[u]){
                if(dist[v] > d + time){
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if(dist[v] == d + time){
                    ways[v] = ( ways[v] + ways[u] )%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};