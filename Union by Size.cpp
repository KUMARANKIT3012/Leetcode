#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // size of each set initially is 1
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 are in the same set
    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same set\n";
    else
        cout << "Different set\n";

    ds.unionBySize(3, 7);

    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same set\n";
    else
        cout << "Different set\n";

    return 0;
}
