class Solution {
public:
    static const long long MOD = 1000000007LL;
    using Matrix = vector<vector<long long>>;
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;
        Matrix T(S, vector<long long>(S, 0));
        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }
            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        vector<long long> base(S, 0);
        for (int v = 0; v < m; v++) {
            base[v] = v;
            base[m + v] = m - 1 - v;
        }
        Matrix P = power(T, n - 2);
        vector<long long> state(S, 0);
        for (int i = 0; i < S; i++) {
            long long val = 0;
            for (int j = 0; j < S; j++) {
                val = (val + P[i][j] * base[j]) % MOD;
            }
            state[i] = val;
        }
        long long ans = 0;
        for (long long x : state) {
            ans = (ans + x) % MOD;
        }
        return (int)ans;
    }
};
