class Solution {
public:
    vector<int> offset = {0,1,0,-1,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j}); //row , col
                }
                    
            }
        }
        
        if(q.size() == n*n)
            return -1;
        
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size){
                auto curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
            
                for(int k=0;k<4;k++){
                    int newrow = row + offset[k];
                    int newcol = col + offset[k+1];
                
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n){
                        if(grid[newrow][newcol]==0){
                            grid[newrow][newcol] = 1;
                            q.push({newrow,newcol});
                        }
                    }
                }
                size--;
            }
        }
        
        return dist-1;
    }
};