class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose:
        int n = matrix.size();
        for(int i = 0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse:
        for(int i=0; i<n; i++){
            // row is mat[i]:
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
