class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ps = 0;
        int ss = 0;
        for(int i = 0; i<n; i++){
            ps += mat[i][i];
            ss += mat[i][n-i-1];
        }

        return (n & 1) ? ps + ss - mat[n/2][n/2] : ps + ss;
    }
};
