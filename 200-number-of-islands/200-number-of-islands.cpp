class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
        }
        
        return;
    }
};