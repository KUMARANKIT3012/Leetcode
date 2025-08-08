class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list from edges
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // Step 2: Calculate indegree for each node
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Push all nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: Process nodes (Kahn's Algorithm)
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // Step 5: If cnt != V → cycle exists
        return cnt != V;
    }
};
