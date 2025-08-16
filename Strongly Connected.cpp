class Solution {
  public:
    void dfs1(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs1(neigh, adj, vis, st);
            }
        }
        st.push(node); // store by finishing time
    }
    
    void dfs2(int node, vector<int> adjT[], vector<int>& vis) {
        vis[node] = 1;
        for (auto neigh : adjT[node]) {
            if (!vis[neigh]) {
                dfs2(neigh, adjT, vis);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Step 1: DFS to get finishing order
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, (vector<int>*)adj.data(), vis, st);
            }
        }
        
        // Step 2: Transpose graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            for (auto neigh : adj[i]) {
                adjT[neigh].push_back(i); // reverse edge
            }
        }
        
        // Step 3: DFS on transposed graph
        fill(vis.begin(), vis.end(), 0);
        int sccCount = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                sccCount++;
                dfs2(node, adjT, vis);
            }
        }
        
        return sccCount;
    }
};
