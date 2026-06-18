class Solution {
public:
    int changes = 0;

    void dfs(int city,
             unordered_map<int, vector<int>>& neighbors,
             unordered_set<long long>& edges,
             vector<bool>& visit) {

        for (int neighbor : neighbors[city]) {
            if (visit[neighbor]) continue;
            long long key = (long long)city * 100000 + neighbor;
            if (edges.count(key)) changes++;
            visit[neighbor] = true;
            dfs(neighbor, neighbors, edges, visit);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> neighbors;
        unordered_set<long long> edges;
        for (auto& c : connections) {
            int a = c[0], b = c[1];
            edges.insert((long long)a * 100000 + b);
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
        }
        vector<bool> visit(n, false);
        visit[0] = true;
        dfs(0, neighbors, edges, visit);
        return changes;
    }
};
