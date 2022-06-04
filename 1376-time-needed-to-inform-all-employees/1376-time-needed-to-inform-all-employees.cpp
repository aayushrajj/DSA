class Solution {
public:
    vector<vector<int>> children;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        children.resize(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                children[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
    
    int dfs(int head , vector<int>& informTime){
        int time = 0;
        for(auto &child : children[head]){
            time = max(time , dfs(child,informTime));
        }
        
        return informTime[head] + time;
    }
};