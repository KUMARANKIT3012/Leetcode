class Solution {
public:
    unordered_map<int, bool> safe;
    bool dfs(int node, vector<vector<int>>& graph) {
        if (safe.count(node))
            return safe[node];

        safe[node] = false;
        for (int nei : graph[node]) {
            if (!dfs(nei, graph))
                return safe[node];
        }
        safe[node] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i, graph))
                ans.push_back(i);
        }
        return ans;
    }
};
