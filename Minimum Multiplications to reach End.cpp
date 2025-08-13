class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(MOD, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            auto [steps, node] = pq.top();
            pq.pop();
            
            if (node == end) return steps;
            
            for (int num : arr) {
                int next = (node * num) % MOD;
                if (steps + 1 < dist[next]) {
                    dist[next] = steps + 1;
                    pq.push({steps + 1, next});
                }
            }
        }
        
        return -1; // If end not reachable
    }
};
