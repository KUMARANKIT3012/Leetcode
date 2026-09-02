class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin;

        for(int i = 0; i < m; i++) {
            int mn = INT_MAX;
            for(int j = 0; j < n; j++) {
                mn = min(mn, matrix[i][j]);
            }
            rowMin.push_back(mn);
        }

        vector<int> ans;

        for(int j = 0; j < n; j++) {
            int mx = INT_MIN;

            for(int i = 0; i < m; i++) {
                mx = max(mx, matrix[i][j]);
            }

            for(int x : rowMin) {
                if(x == mx) {
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};
