class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < N; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        // prims :  
        int res = 0;
        unordered_set<int> visit;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minH;
        minH.push({0, 0});
        while (visit.size() < N) {
            auto [cost, i] = minH.top();
            minH.pop();
            if (visit.count(i))
                continue;
            res += cost;
            visit.insert(i);
            for (auto [neiCost, nei] : adj[i]) {
                if (!visit.count(nei))
                    minH.push({neiCost, nei});
            }
        }
        return res;
    }
};
