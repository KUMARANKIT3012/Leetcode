class Solution {
public:
    int n, m;
    vector<vector<int>> score;
    vector<int> dp;

    int solve(int mask) {
        if (mask == (1 << n) - 1) return 0;
        if (dp[mask] != -1) return dp[mask];

        int student = __builtin_popcount(mask);
        int ans = 0;

        for (int mentor = 0; mentor < n; mentor++) {
            if (!(mask & (1 << mentor))) {
                ans = max( ans, score[student][mentor] + solve(mask | (1 << mentor))
                );
            }
        }
        return dp[mask] = ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students,vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();

        score.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;

                for (int k = 0; k < m; k++) {
                    if (students[i][k] == mentors[j][k]) {
                        cnt++;
                    }
                }
                score[i][j] = cnt;
            }
        }
        dp.assign(1 << n, -1);
        return solve(0);
    }
};
