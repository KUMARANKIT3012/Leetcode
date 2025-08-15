class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
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

class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union all existing 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Try converting each 0 to 1 and calculate max size
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                unordered_set<int> components;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int totalSize = 1; // current cell turned to 1
                for (auto it : components) {
                    totalSize += ds.size[it];
                }
                ans = max(ans, totalSize);
            }
        }

        // Step 3: Edge case (all 1's)
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }

        return ans;
    }
};
