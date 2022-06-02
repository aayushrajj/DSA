class Solution {
public:
    vector<int> cityCount;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        for(int i=0;i<n;i++){
            dijsktra(adj,distanceThreshold,n,i);
        }
        
        int minCity = INT_MAX;
        int ansCity = 0;
        for(int i=0;i<cityCount.size();i++){
            if(cityCount[i] <= minCity){
                minCity = cityCount[i];
                ansCity = i;
            }
        }
        return ansCity;
    }
    
    void dijsktra(vector<vector<pair<int,int>>> &adj , int distanceThreshold , int n , int src){
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                if(distance[it.first] > dist + it.second){
                    distance[it.first] = dist + it.second;
                    pq.push({distance[it.first] , it.first});
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(i!=src && distance[i] <= distanceThreshold)
                count++;
        }
        
        cityCount.push_back(count);
    }
};