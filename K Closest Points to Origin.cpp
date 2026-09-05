class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;

        for(auto& point : points){
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;
            minheap.push({dist, x, y});
        }

        vector<vector<int>> res;

        while(k > 0){
            vector<int> curr = minheap.top();
            minheap.pop();

            int x = curr[1];
            int y = curr[2];

            res.push_back({x, y});
            k--;
        }

        return res;
    }
};
