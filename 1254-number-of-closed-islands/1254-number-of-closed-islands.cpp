class Solution {
public:
    int m,n;
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count =0;
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0)
                dfs(grid,i,0);
            if(grid[i][n-1]==0)
                dfs(grid,i,n-1);
        }
        
        for(int j=0;j<n;j++){
            if(grid[0][j]==0)
                dfs(grid,0,j);
            if(grid[m-1][j]==0)
                dfs(grid,m-1,j);
        }
        
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==1)
            return;
        grid[row][col] = 1;
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
    }
};