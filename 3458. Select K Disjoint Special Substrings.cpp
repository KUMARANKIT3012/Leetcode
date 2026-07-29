class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        if (k == 0) return true;

        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool ok = true;

            for (int i = l; i <= r && ok; i++) {
                int ch = s[i] - 'a';
                if (first[ch] < l) {
                    ok = false;
                    break;
                }
                r = max(r, last[ch]);
            }

            if (ok && !(l == 0 && r == n - 1))
                intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        int cnt = 0;
        int end = -1;

        for (auto &[l, r] : intervals) {
            if (l > end) {
                cnt++;
                end = r;
            }
        }

        return cnt >= k;
    }
};
