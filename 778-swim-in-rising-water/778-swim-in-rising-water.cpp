typedef tuple<int,int,int> pi;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = max(grid[0][0],grid[n-1][n-1]);
        
        vector<vector<int>> dir = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        
        priority_queue<pi, vector<pi> , greater<pi> > pq;
        pq.push({ans,0,0}); // {cost,row,col}
        
        while(!pq.empty()){
            auto [cost,row,col] = pq.top();
            pq.pop();
            
            ans = max(ans,cost);
            
            for(auto d : dir){
                int newrow = row + d[0];
                int newcol = col + d[1];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && !visited[newrow][newcol]){
                    if(newrow==n-1 && newcol==n-1)
                        return ans;
                    pq.push({grid[newrow][newcol],newrow,newcol});
                    visited[newrow][newcol] = 1;
                }
            }
        }
        
        return 0;
    }
};