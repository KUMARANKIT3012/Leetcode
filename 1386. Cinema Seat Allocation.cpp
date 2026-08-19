class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &s : reservedSeats) {
            int r = s[0], c = s[1];
            if (c >= 2 && c <= 9)
                mp[r] |= (1 << c);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[r, mask] : mp) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));
            bool middle = !(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)));

            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};
