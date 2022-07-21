class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0;
        int endCol = mat[0].size()-1;
        
        while(startCol<=endCol){
            int midCol = startCol + (endCol-startCol)/2;
            int maxRow = 0;
            for(int row=0; row<mat.size(); row++){
                if(mat[row][midCol] >= mat[maxRow][midCol])
                    maxRow = row;
            }
            
            bool isLeftBig = midCol-1>=startCol && mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool isRightBig = midCol+1<=endCol && mat[maxRow][midCol+1] > mat[maxRow][midCol];
            
            if(!isLeftBig && !isRightBig)
                return {maxRow,midCol};
            
            if(isLeftBig)
                endCol = midCol-1;
            else if(isRightBig)
                startCol = midCol+1;
        }
        
        return {-1,-1};
    }
};