class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;
            unordered_set<char> st;
            for (int i = first[c] + 1; i < last[c]; i++) st.insert(s[i]);
            ans += st.size();
        }
        return ans;
    }
};
