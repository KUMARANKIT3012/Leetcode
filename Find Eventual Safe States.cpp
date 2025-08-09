class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // Step 1: Reverse the edges
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);
        
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++; // indegree in reversed graph
            }
        }
        
        // Step 2: Queue for topo sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> safeNodes;
        
        // Step 3: Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (int neigh : revGraph[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        
        // Step 4: Sort result (because BFS may not give sorted order)
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
