class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count =0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int landCount = 0;
                    dfs(grid,landCount,i,j);
                    count = max(count,landCount);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid,int &landCount,int row,int col){
        if(row>=0 && row<m && col>=0 && col<n && grid[row][col]){
            landCount++;
            grid[row][col] = 0;
            dfs(grid,landCount,row+1,col);
            dfs(grid,landCount,row-1,col);
            dfs(grid,landCount,row,col+1);
            dfs(grid,landCount,row,col-1);
        }
    }
    
    /*
            grid[row][col] = 0;
        landCount++;
        if(row+1<m && col+1<n && grid[row][col+1]==1){
            dfs(grid,landCount,row,col+1);
        }
        if(row+1<m && col+1<n && grid[row+1][col]==1){
            dfs(grid,landCount,row+1,col);
        }
    */
};