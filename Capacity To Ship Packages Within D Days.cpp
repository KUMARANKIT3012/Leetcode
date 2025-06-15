#include <vector>
#include <numeric> // for accumulate
#include <algorithm> // for max_element
using namespace std;

class Solution {
public:
    int loadcalc(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;
        for (int weight : weights) {
            if (load + weight > cap) {
                days++;
                load = weight;
            } else {
                load += weight;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (loadcalc(weights, mid) <= days) {
                ans = mid;       
                high = mid - 1;
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};
