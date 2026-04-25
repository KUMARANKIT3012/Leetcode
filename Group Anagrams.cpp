class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (auto &s : strs) {
            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + ",";
            }

            res[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &it : res) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
