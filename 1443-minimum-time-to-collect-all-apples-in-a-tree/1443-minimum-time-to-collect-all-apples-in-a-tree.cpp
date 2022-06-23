class Solution {
public:
    vector<vector<int>> adjList;
    vector<bool> fruit;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n);
        fruit = hasApple;
        for(auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        return dfs(0,0).first; //node-->parent
    }
    
    pair<int,int> dfs(int node,int par){
        pair<int,int> v = {0,fruit[node]};
        
        for(auto &i : adjList[node]){
            if(i!=par){
                auto x = dfs(i,node);
                v.first += (2+x.first)*x.second;
                v.second |= x.second;
            }
        }
        
        return v;
    }
};