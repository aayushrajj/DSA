class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            graph[u].push_back({v,p});
            graph[v].push_back({u,p});
        }
        
        
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        
        vector<double> cost(n,0.0);
        cost[start] = 1.0;
        
        while(!pq.empty()){
            auto [prob,node] = pq.top();
            pq.pop();
            
            if(node==end)
                return prob;
            for(auto e : graph[node]){
                // double curr = e.first;
                double currProb = prob * e.second;
                if(cost[e.first] < currProb){
                    cost[e.first] = currProb;
                    pq.push({currProb,e.first});
                }
            }
        }
        return 0.0;
    }
};