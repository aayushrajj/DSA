class Solution {
public:
    int FRESH = 1;
    int EMPTY = 0;
    int ROTTEN = 2;
    vector<int> offset = {0,1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int empty=0,fresh=0,rotten=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==EMPTY)
                    empty++;
                if(grid[i][j]==FRESH)
                    fresh++;
                if(grid[i][j]==ROTTEN)
                    rotten++ , q.push({i,j});
            }
        }
        
        if(empty==m*n)
            return 0;
        if(fresh==m*n)
            return -1;
        
        int dist =0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size){
                auto [row,col] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newrow = row + offset[k];
                    int newcol = col + offset[k+1];
                    if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                        if(grid[newrow][newcol]==FRESH){
                            grid[newrow][newcol] = ROTTEN;
                            q.push({newrow,newcol});
                        }
                    }
                }
                size--;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==FRESH)
                    return -1;
            }
        }
        
        return dist-1;
    }
};