class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) return 0;
        if (s.size() == 2) return -1;
        auto [lo, hi] = minmax_element(s.begin() + 1, s.end() - 1);
        if (s[0] <= min(*lo, s.back()) || max(s[0], *hi) <= s.back()) return 1;
        return s.back() < *lo && *hi < s[0] ? 3 : 2;
    }
};
