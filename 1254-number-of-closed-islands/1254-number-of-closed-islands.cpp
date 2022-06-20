class Solution {
public:
    int m,n;
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count =0;
        
        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count++;
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