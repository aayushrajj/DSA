class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        if(n==0)
            return res;
        int i = 1;
        int colBegin = 0 , rowEnd = n - 1;
        int rowBegin = 0 , colEnd = n-1;
        while(i <= n*n){
            //traverse right
            for(int j=colBegin;j<=colEnd;j++)
                res[rowBegin][j] = i , i++;
            rowBegin++;
            
            // traverse down
            for(int j=rowBegin;j<=rowEnd;j++)
                res[j][colEnd] = i , i++;
            colEnd--;
            
            //traverse left
            for(int j=colEnd;j>=colBegin;j--)
                res[rowEnd][j] = i , i++;
            rowEnd--;
            
            //traverse up
            for(int j=rowEnd;j>=rowBegin;j--)
                res[j][colBegin] = i , i++;
            colBegin++;
        }
        return res;
    }
};