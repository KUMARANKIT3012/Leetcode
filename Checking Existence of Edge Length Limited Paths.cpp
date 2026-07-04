class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        int m = queries.size();
        vector<vector<int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }

        sort(q.begin(), q.end());

        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (rank[a] < rank[b])
                parent[a] = b;
            else if (rank[a] > rank[b])
                parent[b] = a;
            else {
                parent[b] = a;
                rank[a]++;
            }
        };

        vector<bool> ans(m);
        int j = 0;

        for (auto &query : q) {
            int limit = query[0];
            int u = query[1];
            int v = query[2];
            int idx = query[3];

            while (j < edgeList.size() && edgeList[j][2] < limit) {
                unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            ans[idx] = (find(u) == find(v));
        }

        return ans;
    }
};
