class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n==0 || grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;
        
        vector<vector<int>> dir = { {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1} };
        
        queue<pair<int,int>> q;
        q.push({0,0}); //row,col
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            
            if(row==n-1 && col==n-1)
                return grid[row][col];
            
            for(auto d : dir){
                int newrow = row + d[0];
                int newcol = col + d[1];
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n){
                    if(grid[newrow][newcol]==0){
                        grid[newrow][newcol] = grid[row][col] + 1;
                        q.push({newrow,newcol});
                    }
                }
            }   
        }
        
        return -1;
    }
};