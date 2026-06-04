class Solution {
public:
    int waviness(int n) {
        string s = to_string(n);
        int cnt = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            int prev = s[i - 1] - '0';
            int cur  = s[i] - '0';
            int next = s[i + 1] - '0';
            if (cur > prev && cur > next)
                cnt++;
            else if (cur < prev && cur < next)
                cnt++;
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += waviness(i);
        }
        return ans;
    }
};
