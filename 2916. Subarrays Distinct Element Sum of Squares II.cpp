class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();

        vector<long long> bit1(n + 1, 0);
        vector<long long> bit2(n + 1, 0);
        vector<int> last(100001, -1);

        auto prefix_sum = [&](int k) -> long long {
            long long s1 = 0, s2 = 0;
            int index = k;

            while (index > 0) {
                s1 += bit1[index];
                s2 += bit2[index];
                index -= index & -index;
            }

            return k * s1 - s2;
        };

        auto add_boundary = [&](int index, long long delta) {
            long long weighted = delta * (index - 1);

            while (index <= n) {
                bit1[index] += delta;
                bit2[index] += weighted;
                index += index & -index;
            }
        };

        long long total_distinct = 0;
        long long ending_squares = 0;
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int value = nums[i];
            int p = last[value];

            long long affected_sum =
                total_distinct - prefix_sum(p + 1);

            long long length = i - p;

            ending_squares =
                (ending_squares + 2 * affected_sum + length) % MOD;

            answer = (answer + ending_squares) % MOD;

            add_boundary(p + 2, 1);
            add_boundary(i + 2, -1);

            total_distinct += length;
            last[value] = i;
        }

        return (int)answer;
    }
};
