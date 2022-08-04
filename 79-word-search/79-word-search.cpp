class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return false;
        
        m = board.size();
        n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && backtrack(board,word,i,j,0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, string word,int i,int j,int n){
        if(n==word.size()) return true;
        
        if(i>=board.size() || j>=board[i].size() || i<0 || j<0 || board[i][j]!=word[n])
            return false;
        
        // if(i<0 || i>=m || j<0 || j>=board[i].size() || board[i][j]!=word[n]) return false;
        
        board[i][j] = '0';
        
        bool status = backtrack(board, word, i + 1, j, n + 1) ||
                      backtrack(board, word, i, j + 1, n + 1) || 
                      backtrack(board, word, i - 1, j, n + 1) || 
                      backtrack(board, word, i, j - 1, n + 1);
        
        board[i][j] = word[n];
        
        return status;
    }
};