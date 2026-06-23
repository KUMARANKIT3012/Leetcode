class Solution {
public:
    static const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;
        vector<long long> up(m), down(m);
        for (int v = 0; v < m; v++) {
            up[v] = v;             
            down[v] = m - 1 - v;   
        }
        if (n == 2) {
            long long ans = 0;
            for (int v = 0; v < m; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m), newDown(m);

            long long pref = 0;
            for (int v = 0; v < m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            long long suff = 0;
            for (int v = m - 1; v >= 0; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % MOD;
            }
            up = move(newUp);
            down = move(newDown);
        }
        long long ans = 0;
        for (int v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }
        return (int)ans;
    }
};
