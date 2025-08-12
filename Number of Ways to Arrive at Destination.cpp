#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        
        // Step 1: Build graph
        vector<vector<pair<int,long long>>> graph(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1];
            long long time = r[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // Step 2: Dijkstra setup
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        // Step 3: Dijkstra loop
        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();
            
            if (currDist > dist[u]) continue;
            
            for (auto &[v, time] : graph[u]) {
                long long newDist = currDist + time;
                
                // Found a shorter path
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                }
                // Found another shortest path
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1] % MOD;
    }
};
