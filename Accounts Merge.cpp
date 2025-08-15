class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToNode;

        // Step 1: Map emails to accounts and union them
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                } else {
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        // Step 2: Group emails by ultimate parent
        vector<vector<string>> mergedMails(n);
        for (auto &it : mailToNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        // Step 3: Build result with names and sorted emails
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (!mergedMails[i].empty()) {
                sort(mergedMails[i].begin(), mergedMails[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // name
                temp.insert(temp.end(), mergedMails[i].begin(), mergedMails[i].end());
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
