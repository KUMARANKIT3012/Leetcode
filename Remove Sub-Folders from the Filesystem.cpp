class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (string &f : folder) {
            if (ans.empty()) {
                ans.push_back(f);
            } else {
                string &last = ans.back();
                if (f.size() > last.size() &&
                    f.substr(0, last.size()) == last &&
                    f[last.size()] == '/') {
                    continue;
                }
                ans.push_back(f);
            }
        }
        return ans;
    }
};
