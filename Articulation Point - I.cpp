class Solution {
  public:
    int timer;
    vector<int> tin, low, vis, isAP;

    void dfs(int node, int parent, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int childCount = 0;

        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;

            if (!vis[neigh]) {
                dfs(neigh, node, adj);
                low[node] = min(low[node], low[neigh]);

                // articulation point check (non-root)
                if (parent != -1 && low[neigh] >= tin[node]) {
                    isAP[node] = 1;
                }

                childCount++;
            } else {
                // back edge
                low[node] = min(low[node], tin[neigh]);
            }
        }

        // root case
        if (parent == -1 && childCount > 1) {
            isAP[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        vis.assign(V, 0);
        isAP.assign(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) ans.push_back(i);
        }
        if (ans.empty()) return {-1}; // if no AP found
        return ans;
    }
};
