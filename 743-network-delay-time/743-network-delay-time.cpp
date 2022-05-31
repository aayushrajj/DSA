class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> signalReceivedAt(n+1,INT_MAX);
        
        for(auto v : times){
            int source = v[0];
            int dest = v[1];
            int travelTime = v[2];
            adj[source].push_back({travelTime,dest});
        }
        
        
        signalReceivedAt[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int currNodeTime = pq.top().first;
            pq.pop();
            
            for(auto x : adj[node]){
                int time = x.first;
                int neighbourNode = x.second;
                if( signalReceivedAt[neighbourNode] > currNodeTime + time){
                    signalReceivedAt[neighbourNode] = currNodeTime + time;
                    pq.push({signalReceivedAt[neighbourNode], neighbourNode});
                }
            }
        }
        
        
        int minTime = INT_MIN;
        for(int i=1;i<=n;i++){
            minTime = max(minTime , signalReceivedAt[i]);
        }
        
        return minTime==INT_MAX ? -1 : minTime;
    }
};