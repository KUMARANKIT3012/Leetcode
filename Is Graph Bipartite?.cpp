class Solution {
private:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &adj) {
        color[node] = col;

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                // Assign the opposite color to the neighbor
                if (dfs(it, !col, color, adj) == false) return false;
            } else if (color[it] == col) {
                // Same color found in adjacent node → not bipartite
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  // -1 means uncolored

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }

        return true;
    }
};
