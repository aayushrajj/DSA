class UnionFind{
    vector<int> parents;
public:
    int count;
    UnionFind(int n){
        parents.resize(n);
        count = n;
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
    }
    
    int find(int x){
        if(x!=parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void unify(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX!=rootY){
            parents[rootX] = rootY;
            count--;
        }
    }
    
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            int a = row[2*i];
            int b = row[2*i + 1];
            uf.unify(a/2,b/2);
        }
        
        return n - uf.count;
    }
};