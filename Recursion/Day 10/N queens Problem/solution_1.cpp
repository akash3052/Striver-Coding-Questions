class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n){
        // checking lower left diagonal
        int duprow=row, dupcol=col;
        while(row>=0 and col>=0){
            // if(board[row][col] == "Q")
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        // checking left side row
        row = duprow;
        col = dupcol;
        while(col>=0){
            // if(board[row][col] == "Q")
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        // cheking upper left diagonal
        row = duprow;
        col = dupcol;
        while(row<n and col>=0){
            // if(board[row][col] == "Q")
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &res, vector<string> &board, int col, int n){
        if(col == n){
            res.push_back(board);
            return ;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                // board[row][col] = "Q";
                board[row][col] = 'Q';
                solve(res, board, col+1, n);
                // board[row][col] = ".";
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<string>> board(n,vector<string>(n,'.'));
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<vector<string>> res;
        solve(res, board, 0, n);
        return res;
    }
};
