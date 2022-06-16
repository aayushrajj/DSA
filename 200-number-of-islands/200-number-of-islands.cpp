class Solution {
public:
    vector<vector<int>> dir = { {0,1} , {0,-1} , {1,0} , {-1,0} };
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,m,n,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid,int m,int n,int row,int col){
        for(auto d : dir){
            int newrow = row + d[0];
            int newcol = col + d[1];
            if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                if(grid[newrow][newcol]=='1'){
                    grid[newrow][newcol] = '0';
                    dfs(grid,m,n,newrow,newcol);
                }
            }
        }
    }
};