class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, st)) return true;
            } else if (pathVis[it]) {
                return true;  // cycle found
            }
        }

        pathVis[node] = 0;
        st.push(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // edge from prereq to course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis, st)) {
                    return {}; // cycle detected
                }
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};
