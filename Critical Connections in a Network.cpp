class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tin, low, vis;
    int timer;

    void dfs(int node, int parent, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto neigh : adj[node]) {
            if (neigh == parent) continue; // skip the parent edge
            if (!vis[neigh]) {
                dfs(neigh, node, adj);
                low[node] = min(low[node], low[neigh]);
                
                // condition for bridge
                if (low[neigh] > tin[node]) {
                    ans.push_back({node, neigh});
                }
            } else {
                // back edge
                low[node] = min(low[node], tin[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        timer = 0;
        tin.assign(n, -1);
        low.assign(n, -1);
        vis.assign(n, 0);

        dfs(0, -1, adj);
        return ans;
    }
};
