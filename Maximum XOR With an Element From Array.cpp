class Solution {
    struct Node {
        Node* links[2];

        bool contains(int bit) {
            return links[bit] != nullptr;
        }

        Node* get(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }
    };

    Node* root;

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        if (!node->contains(0) && !node->contains(1)) return -1; // no numbers inserted
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->contains(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int q = queries.size();
        vector<int> ans(q);

        // store queries with original index
        vector<array<int, 3>> qWithIdx;
        for (int i = 0; i < q; i++) {
            qWithIdx.push_back({queries[i][0], queries[i][1], i}); 
            // {xi, mi, index}
        }

        // sort by mi
        sort(qWithIdx.begin(), qWithIdx.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        root = new Node();
        int idx = 0; // pointer in nums

        for (auto &query : qWithIdx) {
            int xi = query[0], mi = query[1], qIdx = query[2];

            // insert all nums <= mi
            while (idx < nums.size() && nums[idx] <= mi) {
                insert(nums[idx]);
                idx++;
            }

            // if no element <= mi
            if (idx == 0) {
                ans[qIdx] = -1;
            } else {
                ans[qIdx] = getMax(xi);
            }
        }

        return ans;
    }
};
