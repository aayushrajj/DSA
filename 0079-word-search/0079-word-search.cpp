class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( backtrack(board,word,i,j,0) )
                    return true;
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board,string &word,int row,int col,int idx){
        if(idx == word.length())
            return true;
        
        if(row>m-1 || row<0 || col>n-1 || col<0 || board[row][col] == '*')
            return false;
        
        if(board[row][col] != word[idx])
            return false;
        
        board[row][col] = '*';
        
        bool right = backtrack(board,word,row,col+1,idx+1);
        bool down = backtrack(board,word,row+1,col,idx+1);
        bool left = backtrack(board,word,row,col-1,idx+1);
        bool up = backtrack(board,word,row-1,col,idx+1);
        
        board[row][col] = word[idx];
        
        return right || down || left || up;
    }
};