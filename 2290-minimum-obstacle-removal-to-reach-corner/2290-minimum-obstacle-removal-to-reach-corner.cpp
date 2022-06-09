typedef tuple<int,int,int> ti;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> effort(m,vector<int>(n,INT_MAX));
        effort[0][0] = 0;
        vector<vector<int>> dir = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        
        priority_queue<ti , vector<ti> , greater<ti> > pq;
        pq.push({0,0,0}); // {cost,cellrow,cellcol}
        
        while(!pq.empty()){
            auto [cost,row,col] = pq.top();
            pq.pop();
            
            if(row==m-1 && col==n-1)
                return effort[m-1][n-1];
            
            for(auto d : dir){
                int newrow = row + d[0];
                int newcol = col + d[1];
                if(newrow >=0 && newrow < m && newcol >=0 && newcol < n){
                    int newcost = grid[newrow][newcol] + cost;
                    if(effort[newrow][newcol] > newcost){
                        effort[newrow][newcol] = newcost;
                        pq.push({newcost,newrow,newcol});
                    }
                }
            }
        }
        
        return 0;
    }
};