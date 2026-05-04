class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        unordered_map<char, int> pCount, sCount;

        for (int i = 0; i < p.size(); i++) {
            pCount[p[i]]++;
            sCount[s[i]]++;
        }

        vector<int> res;
        if (sCount == pCount) res.push_back(0);

        int l = 0;
        for (int r = p.size(); r < s.size(); r++) {
            sCount[s[r]]++;

            sCount[s[l]]--;
            if (sCount[s[l]] == 0) {
                sCount.erase(s[l]);
            }

            l++;

            if (sCount == pCount) {
                res.push_back(l);
            }
        }

        return res;
    }
};
