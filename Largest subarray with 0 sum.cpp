class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<long long, int> mp; // prefix sum -> first index
        long long sum = 0;
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                maxlen = i + 1; // subarray from 0 to i
            }
            else if (mp.find(sum) != mp.end()) {
                maxlen = max(maxlen, i - mp[sum]);
            }
            else {
                mp[sum] = i; // store first occurrence
            }
        }

        return maxlen;
    }
};
