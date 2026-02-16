class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min Heap -> {value, row, col}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // Step 1: Push first element of each row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int ans;

        // Step 2: Extract min k times
        while (k--) {
            auto [val, r, c] = pq.top();
            pq.pop();

            ans = val;

            // Step 3: Push next element of same row
            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};
