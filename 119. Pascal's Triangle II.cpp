class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);

        long long val = 1;

        for(int i = 1; i < rowIndex; i++) {
            val = val * (rowIndex - i + 1) / i;
            ans[i] = val;
        }

        return ans;
    }
};
