class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];
            int dist = x*x + y*y;

            if (pq.size() < k) {
                pq.push({dist, {x, y}});
            } else {
                pq.push({dist, {x, y}});
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result.push_back({top.second.first, top.second.second});
        }

        return result;
    }
};
