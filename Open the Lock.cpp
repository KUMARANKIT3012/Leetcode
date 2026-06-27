class Solution {
public:
    vector<string> children(string lock) {
        vector<string> res;

        for (int i = 0; i < 4; i++) {
            string up = lock;
            string down = lock;

            up[i] = (up[i] - '0' + 1) % 10 + '0';
            down[i] = (down[i] - '0' + 9) % 10 + '0';

            res.push_back(up);
            res.push_back(down);
        }

        return res;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());

        if (visit.count("0000"))
            return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");

        while (!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            if (lock == target)
                return turns;

            for (string child : children(lock)) {
                if (!visit.count(child)) {
                    visit.insert(child);
                    q.push({child, turns + 1});
                }
            }
        }
        return -1;
    }
};
