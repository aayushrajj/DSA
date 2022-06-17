//make a disjoint set Data Structure
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
    
    //find the parent root
    int find(int x){
        if(x!=parents[x])
            parents[x] = find(parents[x]); //path compression
        return parents[x];
    }
    
     //unite two nodes and set them to a common parent root
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
            if(ranks[rootX]==ranks[rootY]) // union_by_rank
                ranks[rootY]++;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n+1);
        for(auto &e : edges){
            if( uf.union_set(e[0],e[1]) )
                return {e[0],e[1]};
        }
        return {};
    }
};