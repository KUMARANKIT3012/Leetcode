class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};

        unordered_set<string> seen, res;

        for (int l = 0; l <= s.length() - 10; l++) {
            string cur = s.substr(l, 10);

            if (seen.count(cur)) {
                res.insert(cur);
            }

            seen.insert(cur);
        }

        return vector<string>(res.begin(), res.end());
    }
};
