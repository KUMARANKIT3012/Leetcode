class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int minCount = m + 1;
        int minRowIndex = -1;

        for (int i = 0; i < n; i++) {
            int onesCount = 0;

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    onesCount++;
            }

            if (onesCount < minCount) {
                minCount = onesCount;
                minRowIndex = i;
            }
        }

        return minRowIndex + 1; // rows are 1-indexed
    }
};
