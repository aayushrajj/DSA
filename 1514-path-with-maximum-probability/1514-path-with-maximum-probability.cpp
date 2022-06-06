class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dist(n);
        dist[start] = 1;
        
        for(double i=0;i<n-1;i++){
            bool flag = false;
            for(double j=0;j<edges.size();j++){
                double u = edges[j][0];
                double v = edges[j][1]; 
                if(dist[v] < dist[u] * succProb[j]){
                    dist[v] = dist[u] * succProb[j];
                    flag = true;
                }
                if(dist[u] < dist[v] * succProb[j]){
                    dist[u] = dist[v] * succProb[j];
                    flag = true;
                }
            }
            
            if(!flag)
                break;
        }
          
        return dist[end];   
    }
};