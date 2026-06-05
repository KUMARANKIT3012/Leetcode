class Solution {
public:
    struct Node {
        long long ways, waviness;
    };

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    string s;

    Node solve(int pos, int prev1, int prev2, bool tight, bool started) {
        if (pos == s.size())
            return {1, 0};

        if (vis[pos][prev1][prev2][tight][started])
            return dp[pos][prev1][prev2][tight][started];

        vis[pos][prev1][prev2][tight][started] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool nTight = (tight && d == limit);

            if (!started && d == 0) {
                Node nxt = solve(pos + 1, 10, 10, nTight, false);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness;
            } else {
                int add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                Node nxt = solve(pos + 1, d, prev1, nTight, true);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness + add * nxt.ways;
            }
        }

        return dp[pos][prev1][prev2][tight][started] = ans;
    }

    long long f(long long x) {
        if (x <= 0)
            return 0;

        s = to_string(x);

        memset(vis, false, sizeof(vis));

        return solve(0, 10, 10, true, false).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1 - 1);
    }
};
