class Solution {
public:
    vector<int> offset = {0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,INT_MAX));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j}); // row , col
                    visited[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for(int k=0;k<4;k++){
                int nextrow = row + offset[k];
                int nextcol = col + offset[k+1];
                
                if(nextrow>=0 && nextrow<m && nextcol>=0 && nextcol<n){
                    if(mat[nextrow][nextcol]){
                        if(visited[nextrow][nextcol]>visited[row][col]+1){
                            visited[nextrow][nextcol] = visited[row][col]+1;
                            q.push({nextrow,nextcol});
                        }
                    }
                }
            }
        }
        
        return visited;
    }
};