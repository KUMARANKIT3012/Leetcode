class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            if (mapST.count(c1) && mapST[c1] != c2) return false;
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            mapST[c1] = c2;
            mapTS[c2] = c1;
        }
        return true;
    }
};
