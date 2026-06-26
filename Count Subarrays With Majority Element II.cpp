class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        vector<int> bit(2 * n + 10, 0);

        auto update = [&](int idx) {
            while (idx < bit.size()) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        int pref = 0;
        long long ans = 0;

        update(offset + 1);

        for (int x : nums) {
            pref += (x == target ? 1 : -1);
            ans += query(pref + offset);
            update(pref + offset + 1);
        }

        return ans;
    }
};
