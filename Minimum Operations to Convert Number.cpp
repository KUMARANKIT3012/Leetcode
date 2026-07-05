class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> vis(1001, false);
        queue<pair<int, int>> q;

        q.push({start, 0});
        vis[start] = true;

        while (!q.empty()) {
            auto [x, steps] = q.front();
            q.pop();

            for (int num : nums) {
                vector<int> nxt = {
                    x + num,
                    x - num,
                    x ^ num
                };

                for (int val : nxt) {
                    if (val == goal)
                        return steps + 1;

                    if (val >= 0 && val <= 1000 && !vis[val]) {
                        vis[val] = true;
                        q.push({val, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
