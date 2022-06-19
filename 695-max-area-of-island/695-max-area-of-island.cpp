class Solution {
public:
    int m,n;
    vector<int> offset = {0,1,0,-1,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int currArea = 1;
                    grid[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int newrow = curr.first + offset[k];
                            int newcol = curr.second + offset[k+1];
                            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && grid[newrow][newcol]){
                                grid[newrow][newcol] = 0;
                                currArea++;
                                q.push({newrow,newcol});
                            }
                        }
                    }
                    area = max(area,currArea);
                }
            }
        }
        
        return area;
        
    }
};