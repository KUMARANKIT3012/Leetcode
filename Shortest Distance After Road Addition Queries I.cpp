class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++)
            adj[i].push_back(i + 1);

        vector<int> ans;

        for (auto &q : queries) {
            adj[q[0]].push_back(q[1]);

            vector<int> dist(n, -1);
            queue<int> qu;

            dist[0] = 0;
            qu.push(0);

            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        qu.push(v);
                    }
                }
            }

            ans.push_back(dist[n - 1]);
        }

        return ans;
    }
};
