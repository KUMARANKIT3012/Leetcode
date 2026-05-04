class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = s + s;

        string alt1 = "", alt2 = "";
        for (int i = 0; i < s.length(); i++) {
            alt1 += (i % 2 == 0 ? '0' : '1');
            alt2 += (i % 2 == 0 ? '1' : '0');
        }

        int res = s.length();
        int diff1 = 0, diff2 = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (s[r] != alt1[r]) diff1++;
            if (s[r] != alt2[r]) diff2++;

            if ((r - l + 1) > n) {
                if (s[l] != alt1[l]) diff1--;
                if (s[l] != alt2[l]) diff2--;
                l++;
            }

            if ((r - l + 1) == n) {
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};
