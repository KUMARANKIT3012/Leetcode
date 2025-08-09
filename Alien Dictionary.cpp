class Solution {
  public:
    string findOrder(vector<string> &words) {
        // Step 1: Find unique characters
        unordered_set<char> uniqueChars;
        for (auto &w : words) {
            for (char c : w) uniqueChars.insert(c);
        }
        
        int K = uniqueChars.size(); // number of unique letters
        
        // Step 2: Build adjacency list
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        
        for (char c : uniqueChars) present[c - 'a'] = true;
        
        // Step 3: Create edges from given word list
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    break; // only first difference matters
                }
            }
        }
        
        // Step 4: Topological sort using queue
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node + 'a');
            
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        
        return order;
    }
};
