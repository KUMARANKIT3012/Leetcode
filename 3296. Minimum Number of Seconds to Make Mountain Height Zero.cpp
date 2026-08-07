class Solution {
public:
    bool check(long long mid, int mountainHeight, vector<int>& workerTimes) {
        long long removed = 0;

        for (int w : workerTimes) {
            long long l = 0, r = mountainHeight;

            while (l <= r) {
                long long m = l + (r - l) / 2;
                long long need = 1LL * w * m * (m + 1) / 2;

                if (need <= mid)
                    l = m + 1;
                else
                    r = m - 1;
            }

            removed += r;
            if (removed >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1LL * (*min_element(workerTimes.begin(), workerTimes.end())) *
        mountainHeight * (mountainHeight + 1) / 2;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, mountainHeight, workerTimes))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
