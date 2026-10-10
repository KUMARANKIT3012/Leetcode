class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        for (int i = 0; i < n; i++) {
            diff.push_back(abs(nums1[i] - nums2[i]));
        }

        long long sum = accumulate(diff.begin(), diff.end(), 0LL);
        if (sum <= k) {
            return 0;
        }

        unordered_map<int, int> count;
        priority_queue<pair<int, int>> maxHeap;

        for (int d : diff) {
            if (d != 0) {
                count[d]++;
            }
        }

        for (auto& [num, freq] : count) {
            maxHeap.push({num, freq});
        }

        while (k > 0 && !maxHeap.empty()) {
            auto [maxNum, maxNumFreq] = maxHeap.top();
            maxHeap.pop();

            int numDecreased = min(k, (long long)maxNumFreq);
            k -= numDecreased;

            if (maxNumFreq > numDecreased) {
                maxHeap.push({maxNum, maxNumFreq - numDecreased});
            }

            if (!maxHeap.empty() && maxHeap.top().first == maxNum - 1) {
                auto [secondMaxNum, secondMaxNumFreq] = maxHeap.top();
                maxHeap.pop();
                maxHeap.push({secondMaxNum, secondMaxNumFreq + numDecreased});
            } else if (maxNum > 1) {
                maxHeap.push({maxNum - 1, numDecreased});
            }
        }

        long long ans = 0;

        while (!maxHeap.empty()) {
            auto [num, freq] = maxHeap.top();
            maxHeap.pop();
            ans += 1LL * num * num * freq;
        }

        return ans;
    }
};
