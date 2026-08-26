class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;
        int left = 0, ones = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            while (ones > k || (ones == k && s[left] == '0')) {
                if (s[left] == '1') ones--;
                left++;
            }

            if (ones == k) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                } else if (len == minLen) {
                    string cand = s.substr(left, len);
                    if (cand < ans) ans = cand;
                }
            }
        }

        return ans;
    }
};
