class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        while(k--){
            vector<vector<int>> temp(m,vector<int> (n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==n-1 && i==m-1)
                        temp[0][0] = grid[i][j];
                    else if(j==n-1)
                        temp[i+1][0] = grid[i][j];
                    else
                        temp[i][j+1] = grid[i][j];
                }
            }
            grid = temp;
            temp.clear();
        }
        return grid;
    }
};