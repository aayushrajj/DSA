class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c) return mat;
        
        vector<vector<int>> res(r,vector<int>(c,0));
        int x=0,y=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j] = mat[x][y];
                if(y==n-1)
                    y=0,x++;
                else
                    y++;
            }
        }
        
        return res;
    }
};