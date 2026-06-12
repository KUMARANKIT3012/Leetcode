class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n + 1));
        vector<int> depth(n + 1, 0);

        function<void(int, int)> dfs = [&](int u, int p) {
            up[0][u] = p;
            for (int i = 1; i < LOG; i++) {
                up[i][u] = up[i - 1][up[i - 1][u]];
            }

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };

        dfs(1, 0);

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];
            for (int i = 0; i < LOG; i++) {
                if (diff & (1 << i)) {
                    a = up[i][a];
                }
            }

            if (a == b) return a;

            for (int i = LOG - 1; i >= 0; i--) {
                if (up[i][a] != up[i][b]) {
                    a = up[i][a];
                    b = up[i][b];
                }
            }

            return up[0][a];
        };

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int L = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(pow2[dist - 1]);
            }
        }

        return ans;
    }
};
