// RECURSION - 
class Solution {
public:
    int solve(int ind, vector<int>& arr, int k) {
        if (ind == arr.size()) return 0; // base case

        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        
        for (int j = ind; j < min(ind + k, (int)arr.size()); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, arr, k);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solve(0, arr, k);
    }
};




// MEMOIZATION - 
class Solution {
public:
    int solve(int ind, vector<int>& arr, int k, vector<int>& dp) {
        if (ind == arr.size()) return 0;
        if (dp[ind] != -1) return dp[ind];

        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        
        for (int j = ind; j < min(ind + k, (int)arr.size()); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

            for (int j = ind; j < min(ind + k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};
