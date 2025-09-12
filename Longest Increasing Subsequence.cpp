class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = 0 + f(ind + 1, prev_ind, nums, n, dp); // not take

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len = max(len, 1 + f(ind + 1, ind, nums, n, dp)); // take
        }

        return dp[ind][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};



// TABULATION - 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // every element is at least length 1
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};


// using binary search - 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for (int x : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), x);

            if (it == temp.end()) {
                temp.push_back(x);
            } else {
                *it = x;
            }
        }

        return temp.size();
    }
};

