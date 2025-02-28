class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    // mark the i-th row:
                    matrix[i][0] = 0;
                    // mark the j-th col:
                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }

                }
            }
        }
        for(int i = 1; i<m; i++){ // solving 1st part
            for(int j=1; j<n; j++){
                if(matrix[i][j] != 0){
                    // check for col and row:
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }

                }
            }
        }
        if(matrix[0][0] == 0){ // solving 2nd part
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){ // solving 3rd part
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
