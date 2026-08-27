class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<vector<int>> state(n + 1);
        state[0] = freq;

        int matched = 0;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (state[i][x] == 0)
                break;

            state[i + 1] = state[i];
            state[i + 1][x]--;
            matched++;
        }

        for (int i = min(matched, n - 1); i >= 0; i--) {
            vector<int> f = state[i];
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (f[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);
                    f[c]--;

                    for (int j = 0; j < 26; j++)
                        ans += string(f[j], char('a' + j));

                    return ans;
                }
            }
        }

        return "";
    }
};
