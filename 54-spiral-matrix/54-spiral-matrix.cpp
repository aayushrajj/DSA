class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        if(n==0)
            return res;
        int colBegin = 0 , rowEnd = n - 1;
        int rowBegin = 0 , colEnd = m-1;
        while(res.size() < n*m){
            //traverse right
            for(int j=colBegin;j<=colEnd && res.size() < n*m ;j++)
                res.push_back(matrix[rowBegin][j]);
            rowBegin++;
            
            // traverse down
            for(int j=rowBegin;j<=rowEnd && res.size() < n*m ;j++)
                res.push_back(matrix[j][colEnd]);
            colEnd--;
            
            //traverse left
            for(int j=colEnd;j>=colBegin && res.size() < n*m ;j--)
                res.push_back(matrix[rowEnd][j]);
            rowEnd--;
            
            //traverse up
            for(int j=rowEnd;j>=rowBegin && res.size() < n*m ;j--)
                res.push_back(matrix[j][colBegin]);
            colBegin++;
        }
        return res;
    }
};