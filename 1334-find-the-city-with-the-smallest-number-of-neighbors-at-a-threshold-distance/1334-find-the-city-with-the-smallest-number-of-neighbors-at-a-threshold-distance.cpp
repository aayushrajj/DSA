class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int INF = (int) 1e6; // INF = n * maxWeight = 100 * 10^4 = 10^6
        vector<vector<int>> dist(n,vector<int>(n,INF));
        
        //initialize
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            dist[u][v] = edge[2];
            dist[v][u] = edge[2];
        }
        
        //choice diagram
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
                }
            }
        }
        
        int ansCity=0;
        int minCity=INT_MAX;
        for(int i=0;i<n;i++){
            int current=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold)
                    current++;
            }
            if(current<=minCity){
                minCity = current;
                ansCity = i;
            }
        }
        
        return ansCity;
    }
};