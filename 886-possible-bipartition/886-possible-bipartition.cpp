class UnionFind{
private:
    vector<int> parents;
    vector<int> ranks;
    int size;
public:
    UnionFind(int n){
        size = n;
        parents.resize(size);
        ranks.resize(size,0);
        
        for(int i=0;i<size;i++){
            parents[i] = i;
        }
    }
    
    int find(int x){
        if(x!=parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }
    
    bool union_set(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY)
            return false;
        if(ranks[rootX]>ranks[rootY])
            parents[rootY] = rootX;
        else{
            parents[rootX] = rootY;
            if(ranks[rootX]==ranks[rootY])
                ranks[rootY]++;
        }
        return true;
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adjMap;
        
        for(auto &d : dislikes){
            adjMap[d[0]].push_back(d[1]);
            adjMap[d[1]].push_back(d[0]);
        }
        
        UnionFind uf(n+1);
        
        for(auto &pair : adjMap){
            auto currVec = pair.second;
            int first = currVec[0];
            for(int i=1;i<currVec.size();i++){
                uf.union_set(first,currVec[i]); 
                // making pair for all disliked people by the key
            }
        }
        
        //checking if two disliking people are in same set
        for(auto &d : dislikes){
            if(uf.find(d[0]) == uf.find(d[1]))
                return false;
        }
        
        return true;
    }
};