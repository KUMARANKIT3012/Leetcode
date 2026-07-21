class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        int bestMerge = 0;
        int prevZeroGroup = INT_MIN;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            if (s[i] == '1') {
                totalOnes += len;
            } else {
                bestMerge = max(bestMerge, prevZeroGroup + len);
                prevZeroGroup = len;
            }
            i = j;
        }
        return totalOnes + bestMerge;
    }
};
