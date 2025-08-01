class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Step 1: Convert adjacency matrix to adjacency list
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Step 2: Initialize visited array
        vector<int> visited(n, 0);
        int provinces = 0;

        // Step 3: Run DFS for each unvisited node
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adjList, visited);
            }
        }

        return provinces;
    }
};

