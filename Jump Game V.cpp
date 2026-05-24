class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& arr, int d) {
        if (dp[i] != -1) return dp[i];

        int ans = 1;
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + solve(j, arr, d));
        }
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + solve(j, arr, d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);

        int res = 1;

        for (int i = 0; i < n; i++) {
            res = max(res, solve(i, arr, d));
        }

        return res;
    }
};
