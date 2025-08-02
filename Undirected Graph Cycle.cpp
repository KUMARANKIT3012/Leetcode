// using BFS
class Solution {
  public:
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) {
                    return true; // Cycle found
                }
            }
        }

        return false; // No cycle found from this node
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        // Step 1: Convert edge list to adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // because undirected graph
        }

        // Step 2: Visited array
        int vis[V] = {0};

        // Step 3: Apply BFS to each disconnected component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }

        return false; // No cycle found in any component
    }
};




// using DFS: 
class Solution {
private:
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;

        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, vis, adj) == true)
                    return true;
            } else if (adjacentNode != parent) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle found
    }

public:
    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // visited array

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }

        return false; // No cycle in any component
    }
};
