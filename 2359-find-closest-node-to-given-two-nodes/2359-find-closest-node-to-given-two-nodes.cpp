typedef pair<int,int> t;
class Solution {
public:
    int n;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<n;i++){
            if(edges[i]>=0)
                adj[i].push_back({edges[i],1});
        }
        
        vector<int> dist1 = bfs(adj,node1);
        vector<int> dist2 = bfs(adj,node2);
        
        int res = -1;
        int curr = INT_MAX;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if( curr > max(dist1[i],dist2[i]) ){
                    curr = max(dist1[i],dist2[i]);
                    res = i;
                }
            }
        }
        
        return res;
    }
    
    vector<int> bfs(vector<pair<int,int>> adj[],int node){
        priority_queue<t,vector<t>,greater<t>> pq;
        vector<int> dist(n,INT_MAX);
        dist[node] = 0;
        pq.push({0,node}); // dist,node
        
        while(!pq.empty()){
            auto currNode = pq.top().second;
            auto currDist = pq.top().first;
            pq.pop();
            
            for(auto [next,nextDist] : adj[currNode]){
                if(dist[next] > nextDist+currDist){
                    dist[next] = nextDist + currDist;
                    pq.push({dist[next],next});
                }
            }
        }
        
        return dist;
    }
};