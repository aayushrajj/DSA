class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        // this is just a vector of strings with each string size ==n and
        // filled with .
        vector<string> board(n,string(n,'.')); 
        dfs(board,0);
        return res;
    }
    
    
    bool is_valid(vector<string> &board,int row,int col){
        for(int i=row;i>=0;i--)
            if(board[i][col]=='Q') return false;
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j]=='Q') return false;
        
        for(int i=row,j=col;i>=0 && col<board.size();i--,j++)
            if(board[i][j]=='Q') return false;
        
        return true;
        
    } 
        
    void dfs(vector<string> board,int row){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        
        for(int j=0;j<board.size();j++){
            if(is_valid(board,row,j)){
                board[row][j] = 'Q';
                dfs(board,row+1);
                board[row][j] = '.';
            }
        }      
    }
    
    
};