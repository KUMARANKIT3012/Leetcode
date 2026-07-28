class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string half = "";
        char middle = '\0';
        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
            if (freq[i] % 2) middle = 'a' + i;
        }
        string ans = half;
        if (middle != '\0') ans += middle;
        reverse(half.begin(), half.end());
        ans += half;
        return ans;
    }
};
