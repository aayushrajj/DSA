class UnionFind{
    vector<int> parents , ranks;
public:
    UnionFind(int n){
        parents.resize(n);
        ranks.resize(n);
        for(int i=0;i<n;i++){
            parents[i] = i;
            ranks[i] = 1;
        }
    }
    
    int find(int x){
        if(x!=parents[x])
            parents[x] = find(parents[x]); //path compression
        return parents[x];
    }
    
    bool union_set(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)
            return true;
        if(ranks[rootX] > ranks[rootY]){
            parents[rootY] = rootX;
        }
        else{
            parents[rootX] = rootY;
            if(ranks[rootX]==ranks[rootY])
                ranks[rootY]++;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for(auto &e : edges){
            if( uf.union_set(e[0]-1,e[1]-1) )
                return {e[0],e[1]};
        }
        return {};
    }
};