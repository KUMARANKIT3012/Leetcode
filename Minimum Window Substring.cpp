class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, minLen = INT_MAX;

        while (right < s.size()) {
            char c = s[right];
            right++;

            // Update window count
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            // if valid hai toh try to shrink window
            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
