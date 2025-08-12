#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build graph
        vector<vector<pair<int,int>>> graph(n);
        for (auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            graph[u].push_back({v, w});
        }
        
        // Min-heap: {cost_so_far, current_node, stops_so_far}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        
        // Cost table: cost[node][stops] = min cost to reach node with given stops
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));
        cost[src][0] = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int currCost = cur[0], u = cur[1], stops = cur[2];
            
            // If destination reached
            if (u == dst) return currCost;
            
            // If we can still take more flights
            if (stops <= k) {
                for (auto &edge : graph[u]) {
                    int v = edge.first, w = edge.second;
                    int newCost = currCost + w;
                    if (newCost < cost[v][stops + 1]) {
                        cost[v][stops + 1] = newCost;
                        pq.push({newCost, v, stops + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};
