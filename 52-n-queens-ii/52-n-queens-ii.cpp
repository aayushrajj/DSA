class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        return backtrack(board,0);
    }
    
    bool is_valid(vector<vector<int>> &board , int row , int col){
        for(int i=row;i>=0;i--)
            if(board[i][col]) return false;
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j]) return false;
        
        for(int i=row,j=col;i>=0 && j<board.size();i--,j++)
            if(board[i][j]) return false;
        
        return true;
    }
    
    int backtrack(vector<vector<int>> &board,int row){
        if(row==board.size())
            return 1;
        int count=0;
        
        for(int j=0;j<board.size();j++){
            if(is_valid(board,row,j)){
                board[row][j] = 1;
                count += backtrack(board,row+1);
                board[row][j] = 0;
            }
        }
        
        return count;
    }
};