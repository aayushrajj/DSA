class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& isConnected,vector<int> &visited,int city){
        for(int other=0;other<isConnected.size();other++){
            if(isConnected[city][other]==1 && !visited[other]){
                visited[other] = 1;
                dfs(isConnected,visited,other);
            }
        }
    }
};