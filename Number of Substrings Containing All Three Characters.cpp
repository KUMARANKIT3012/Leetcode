class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1, lastB = -1, lastC = -1;
        int res = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') lastA = i;
            else if (s[i] == 'b') lastB = i;
            else if (s[i] == 'c') lastC = i;

            if (lastA != -1 && lastB != -1 && lastC != -1) {
                res += min({lastA, lastB, lastC}) + 1;
            }
        }

        return res;
    }
};
