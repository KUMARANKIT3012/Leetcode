class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int srow = 0;
        int scol = 0;
        int erow = n - 1;
        int ecol = n - 1;
        int num = 1;

        while (srow <= erow && scol <= ecol) {

            // Top row
            for (int i = scol; i <= ecol; i++) {
                mat[srow][i] = num++;
            }

            // Right column
            for (int j = srow + 1; j <= erow; j++) {
                mat[j][ecol] = num++;
            }

            // Bottom row
            if (srow != erow) {
                for (int i = ecol - 1; i >= scol; i--) {
                    mat[erow][i] = num++;
                }
            }

            // Left column
            if (scol != ecol) {
                for (int j = erow - 1; j >= srow + 1; j--) {
                    mat[j][scol] = num++;
                }
            }

            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return mat;
    }
};
