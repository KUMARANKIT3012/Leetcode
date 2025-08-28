class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int i = 0, j = 0;
        int contentChildren = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                // Cookie satisfies the child
                contentChildren++;
                i++;
                j++;
            } else {
                // Cookie too small, try next larger cookie
                j++;
            }
        }
        return contentChildren;
    }
};



// NOTE - 🔹 Why Greedy > DP here?
// DP checks every possible assignment (like knapsack), leading to O(n*m).
// Greedy leverages the sorted order and guarantees optimal matching in linear scan after sorting.

// So:
// For learning purposes → Memoization / Tabulation / Space optimized DP are fine.
// For real submission → Use Greedy (the code you already had originally).



// MEMOIZATION - 
class Solution {
public:
    int solve(int i, int j, vector<int>& g, vector<int>& s, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0; // no child or no cookie
        if(dp[i][j] != -1) return dp[i][j];

        // Option 1: Skip this cookie
        int ans = solve(i, j-1, g, s, dp);

        // Option 2: Assign this cookie if it fits
        if(s[j-1] >= g[i-1]) {
            ans = max(ans, 1 + solve(i-1, j-1, g, s, dp));
        }
        return dp[i][j] = ans;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, g, s, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j-1]; // skip cookie
                if(s[j-1] >= g[i-1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};




// SPACE-OPTIMIZATION - 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                curr[j] = prev[j]; // skip child
                curr[j] = max(curr[j], curr[j-1]); // skip cookie
                if(s[j-1] >= g[i-1]) {
                    curr[j] = max(curr[j], 1 + prev[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

