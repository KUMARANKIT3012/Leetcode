class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPop = 0;
        int ans = 1950;

        for (int year = 1950; year <= 2050; year++) {
            int cnt = 0;

            for (auto &person : logs) {
                if (person[0] <= year && year < person[1]) {
                    cnt++;
                }
            }

            if (cnt > maxPop) {
                maxPop = cnt;
                ans = year;
            }
        }

        return ans;
    }
};
