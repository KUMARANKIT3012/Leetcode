class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, max_freq = 0, max_length = 0;
        unordered_map<char, int> freq;

        for (right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);

            // If the remaining characters exceed k, shrink the window
            if ((right - left + 1) - max_freq > k) {
                freq[s[left]]--;
                left++;
            }

            // Update the max length of valid substring
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
