class Solution {
public:
    // Function to check if s1 is predecessor of s2
    bool checkPossible(string &s1, string &s2) {
        if(s1.size() + 1 != s2.size()) return false;

        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                i++; j++;
            } else {
                j++;
            }
        }
        return (i == s1.size());
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(checkPossible(words[prev], words[i]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
