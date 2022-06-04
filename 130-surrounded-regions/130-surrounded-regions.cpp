class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dfs(board,m,n,i,0);
            if(board[i][n-1]=='O')
                dfs(board,m,n,i,n-1);
        }
        
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                dfs(board,m,n,0,j);
            if(board[m-1][j]=='O')
                dfs(board,m,n,m-1,j);
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]=='#')
                    board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board , int m , int n , int i , int j){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O')
            return;
        
        board[i][j] = '#';
        dfs(board,m,n,i-1,j);
        dfs(board,m,n,i+1,j);
        dfs(board,m,n,i,j-1);
        dfs(board,m,n,i,j+1);
    }
};