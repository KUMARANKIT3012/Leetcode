class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq; // To store frequency of elements in the window
        int left = 0, maxLen = 0;

        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;

            // If there are more than 2 distinct elements, shrink from left
            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]); // Remove element if its frequency becomes 0
                }
                left++; // Move left pointer
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
