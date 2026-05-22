class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            int value = happiness[i] - i;
            if(value > 0) {
                ans += value;
            }
        }
        return ans;
    }
};
