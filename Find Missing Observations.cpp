class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for (int x : rolls) sum += x;
        int total = mean * (m + n);
        int rem = total - sum;

        if (rem < n || rem > 6 * n) return {};
        vector<int> ans(n, rem / n);
        int extra = rem % n;
        for (int i = 0; i < extra; i++) ans[i]++;
        return ans;
    }
};
