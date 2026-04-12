class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max heap
        priority_queue<int> pq;

        // Push all stones into heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // Process until one or zero stones left
        while (pq.size() > 1) {
            int largest = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            if (largest != second) {
                pq.push(largest - second);
            }
        }

        // If one stone remains
        if (!pq.empty()) return pq.top();

        return 0;
    }
};
