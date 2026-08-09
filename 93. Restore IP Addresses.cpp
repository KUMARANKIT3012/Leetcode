class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int parts, string current) {
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back();
                ans.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            if (part.size() > 1 && part[0] == '0')
                continue;

            if (stoi(part) > 255)
                continue;

            solve(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "");

        return ans;
    }
};
