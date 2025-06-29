#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        int maxVal = INT_MIN;
        int start = 0, end = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][0];
            minHeap.push({val, i, 0});
            maxVal = max(maxVal, val);
        }

        while (true) {
            auto [minVal, row, col] = minHeap.top();
            minHeap.pop();

            if (maxVal - minVal < end - start) {
                start = minVal;
                end = maxVal;
            }

            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                maxVal = max(maxVal, nextVal);
            } else {
                break;
            }
        }

        return {start, end};
    }
};
