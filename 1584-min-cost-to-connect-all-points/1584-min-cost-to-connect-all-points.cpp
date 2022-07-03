class UnionFind{
private:
    vector<int> parent,ranks;
public:
    UnionFind(int n){
        parent.resize(n);
        ranks.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x!=parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unify(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY)
            return false;
        if(ranks[rootX]>ranks[rootY])
            parent[rootY] = rootX;
        else{
            parent[rootX] = rootY;
            if(ranks[rootX]==ranks[rootY])
                ranks[rootY]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>> allEdges;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int weight = abs(points[i][0]-points[j][0]) + 
                             abs(points[i][1]-points[j][1]);
                allEdges.push_back({weight,{i,j}});
            }
        }
        
        sort(allEdges.begin(),allEdges.end()); // w.r.t weight of edges
        
        UnionFind uf(n);
        int mstCost =0;
        int edgesUsed =0;
        for(int i=0;i<allEdges.size() && edgesUsed<n-1;i++){
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;
            
            if(uf.unify(node1,node2)){
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
};