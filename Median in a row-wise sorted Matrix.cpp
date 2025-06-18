class Solution {
  public:
    int upperbound(vector<int>& row, int target) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    int median(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();
        int low = 1, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < r; ++i) {
                count += upperbound(mat[i], mid);
            }
            if (count <= (r * c) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
