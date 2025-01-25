class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n){ // TC: O(n)
        // horizontal:
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        // vertically:
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // --> diagonally:
        //(1) left diagonal:
        for(int i=row,j=col; j>=0 && i>=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //(2) right diagonal:
        for(int i=row,j=col; j<n && i>=0; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }   
        return true; 
    }
    void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back({board});
            return;
        }


        for(int j=0; j<n; j++){
            if(isSafe(board, row, j , n)){
                board[row][j] = 'Q';
                nqueens(board, row+1, n, ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueens(board, 0, n, ans);
        return ans;
    }
};
