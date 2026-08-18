class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(51, 0);
        for (int i = 0; i <= n - k; i++) {
            set<int> s;
            for (int j = i; j < i + k; j++) s.insert(nums[j]);
            for (int x : s) cnt[x]++;
        }
        for (int x = 50; x >= 0; x--) {
            if (cnt[x] == 1) return x;
        }
        return -1;
    }
};
