class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        // horizontal:
        for(int j = 0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }
        // vertical:
        for(int i=0; i<9; i++){
            if(board[i][col]==dig){
                return false;
            }
        }

        // grid:
        int srow=(row/3)*3; // har grid ka srow hai 
        int scol=(col/3)*3; // har grid ka scol hai 
        for(int i= srow; i<= srow+2; i++){ // 2 place hi aage jaegi
            for(int j= scol; j<=scol+2; j++){ // similar for col 
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        // Base Case:
        if(row == 9){
            return true;
        } 
        // initializing nextrow and nextcol 
        int nextrow = row, nextcol = col+1;
        //  if col reaches end then increase row by 1 and make col from 1 again 
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        // kya hamara cell fill to nahi hai 
        if(board[row][col] != '.'){
            // fill hai toh next cell ki call lagani hai 
           return helper(board, nextrow, nextcol);
        }

        // placing digit if cell is not filled:
        for(char dig = '1'; dig<='9' ; dig++){
            // place karne se pehle we are checking if it is safe to place 
            if(isSafe(board, row, col, dig)){
                board[row][col] = dig; // cell pe digit place 
                if(helper(board, nextrow, nextcol)){
                    return true;
                }
                board[row][col] = '.'; // Backtracking step
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
