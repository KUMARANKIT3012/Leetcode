class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        auto lcm = [](long long a, long long b) {
            return a / gcd(a, b) * b;
        };
        auto count = [&](long long x) {
            long long ans = 0;
            int n = coins.size();
            for (int mask = 1; mask < (1 << n); mask++) {
                long long mul = 1;
                bool ok = true;
                int bits = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        mul = lcm(mul, coins[i]);
                        if (mul > x) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    long long val = x / mul;
                    if (bits & 1)
                        ans += val;
                    else
                        ans -= val;
                }
            }
            return ans;
        };
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
