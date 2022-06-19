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
                    int landCount = dfs(grid,i,j);
                    count = max(count,landCount);
                }
            }
        }
        return count;
    }
    
    int dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 || row>=m || col<0 || col>=n || !grid[row][col])
            return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid,row+1,col) + dfs(grid,row-1,col) + dfs(grid,row,col+1) + dfs(grid,row,col-1);
    }
};