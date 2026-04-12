class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min heap (frequency, element)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Step 3: Process elements
        for (auto it : freq) {
            if (pq.size() < k) {
                pq.push({it.second, it.first});
            } else {
                pq.push({it.second, it.first});
                pq.pop(); // removes smallest freq (like heappushpop)
            }
        }

        // Step 4: Extract result
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
