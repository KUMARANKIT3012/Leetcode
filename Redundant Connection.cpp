class Solution {
public:
    vector<int> parent, sz;
    int find(int node) {
        int p = parent[node];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool unite(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);
        if (p1 == p2)
            return false;
        if (sz[p1] > sz[p2]) {
            parent[p2] = p1;
            sz[p1] += sz[p2];
        } else {
            parent[p1] = p2;
            sz[p2] += sz[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!unite(u, v))
                return {u, v};
        }
        return {};
    }
};
