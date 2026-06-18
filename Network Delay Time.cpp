class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            edges[u].push_back({v, w});
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        minHeap.push({0, k});
        unordered_set<int> visit;
        int ans = 0;
        while (!minHeap.empty()) {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();
            if (visit.count(n1))
                continue;
            visit.insert(n1);
            ans = max(ans, w1);
            for (auto& [n2, w2] : edges[n1]) {
                if (!visit.count(n2)) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }
        return visit.size() == n ? ans : -1;
    }
};
