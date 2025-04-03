class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            while (hashSet.find(s[right]) != hashSet.end()) {
                hashSet.erase(s[left]);
                left++;
            }
            hashSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
