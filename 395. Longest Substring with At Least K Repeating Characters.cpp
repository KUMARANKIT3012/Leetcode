class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int unique = 1; unique <= 26; unique++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int distinct = 0, good = 0;

            while (right < s.size()) {
                if (freq[s[right] - 'a'] == 0)
                    distinct++;

                freq[s[right] - 'a']++;

                if (freq[s[right] - 'a'] == k)
                    good++;

                while (distinct > unique) {
                    if (freq[s[left] - 'a'] == k)
                        good--;

                    freq[s[left] - 'a']--;

                    if (freq[s[left] - 'a'] == 0)
                        distinct--;

                    left++;
                }

                if (distinct == unique && good == unique)
                    ans = max(ans, right - left + 1);

                right++;
            }
        }

        return ans;
    }
};
