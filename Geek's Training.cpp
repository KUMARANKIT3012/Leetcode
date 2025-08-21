// MEMOIZATION (DP) : 
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        // Base case: first day
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int points = arr[day][task] + f(day-1, task, arr, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); // last = 0,1,2,3
        return f(n-1, 3, arr, dp);
    }
};


// TABULATION : 
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        // Base case (day 0)
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        // Fill dp table
        for(int day = 1; day < n; day++) {
            for(int last = 0; last < 4; last++) {
                dp[day][last] = 0;  // reset
                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }
        
        return dp[n-1][3]; // last=3 means no restriction
    }
};



// SPACE_OPTIMIZATION : 
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(4, 0);
        
        // Base case for day 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        // Fill DP iteratively
        for(int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++) {
                temp[last] = 0;
                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        temp[last] = max(temp[last], arr[day][task] + prev[task]);
                    }
                }
            }
            prev = temp; // Move to next day
        }
        
        return prev[3]; // last = 3 means no restriction
    }
};

