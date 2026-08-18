class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size() && i < k; i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        while (k-- && !pq.empty()) {
            auto [sum, p] = pq.top();
            pq.pop();
            int i = p.first, j = p.second;
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size())
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
        return ans;
    }
};
