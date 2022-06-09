class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> effort(m,vector<int>(n,INT_MAX));
        effort[0][0] = 0;
        
        vector<vector<int>> dir = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        
        deque<pair<int,int>> dq;
        dq.push_back({0,0}); // {cellrow,cellcol}
        
        while(!dq.empty()){
            auto [row,col] = dq.front();
            dq.pop_front();
            
            for(auto d : dir){
                int newrow = row + d[0];
                int newcol = col + d[1];
                if(newrow >=0 && newrow < m && newcol >=0 && newcol < n){
                    if(!visited[newrow][newcol]){
                        effort[newrow][newcol] = effort[row][col] + grid[newrow][newcol];
                        if(grid[newrow][newcol]==1)
                            dq.push_back({newrow,newcol});
                        else
                            dq.push_front({newrow,newcol});
                        
                        visited[newrow][newcol] = 1;
                    }
                }
            }
        }
        
        return effort[m-1][n-1];
    }
};