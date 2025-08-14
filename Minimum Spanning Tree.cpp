#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[py] < rank[px]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Sort edges based on weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(V);
        int mstWeight = 0;
        int edgesUsed = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                mstWeight += wt;
                edgesUsed++;
                if (edgesUsed == V - 1) break; // MST complete
            }
        }
        return mstWeight;
    }
};
