class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        // Step 1: Create Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int x : arr) {
            pq.push(x);
        }

        int cost = 0;

        // Step 2: Keep merging until one rope remains
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int sum = first + second;
            cost += sum;

            pq.push(sum);
        }

        return cost;
    }
};
