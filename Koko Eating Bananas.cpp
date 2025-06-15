#include <vector>
#include <algorithm>
#include <cmath>  // For ceil
using namespace std;

class Solution {
public:
    // Helper function using std::ceil
    bool canEatAll(const vector<int>& piles, int k, int h) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += ceil((double)pile / k);  // ceil
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
