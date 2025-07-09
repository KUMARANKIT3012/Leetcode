class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        // Step 1: Sort by end time (second element of each interval)
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // Step 2: Count maximum non-overlapping intervals
        int count = 1; // always select the first interval
        int last_end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= last_end) {
                count++;
                last_end = intervals[i][1];
            }
        }

        // Step 3: Subtract from total to get number of intervals to remove
        return n - count;
    }
};
