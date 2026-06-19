class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> res;

    bool dfs(string src, int totalTickets) {
        if (res.size() == totalTickets + 1)
            return true;

        if (!adj.count(src))
            return false;

        vector<string> temp = adj[src];

        for (int i = 0; i < temp.size(); i++) {
            string dst = temp[i];

            adj[src].erase(adj[src].begin() + i);
            res.push_back(dst);

            if (dfs(dst, totalTickets))
                return true;

            adj[src].insert(adj[src].begin() + i, dst);
            res.pop_back();
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        for (auto& ticket : tickets)
            adj[ticket[0]].push_back(ticket[1]);

        res.push_back("JFK");

        dfs("JFK", tickets.size());

        return res;
    }
};
