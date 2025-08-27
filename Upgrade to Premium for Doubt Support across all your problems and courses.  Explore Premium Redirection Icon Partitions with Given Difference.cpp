// memoization : 
class Solution {
  public:
    const int MOD = 1e9+7;
    
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(target == 0 && arr[0] == 0) return 2; // pick or not pick zero
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = f(ind-1, target, arr, dp);
        int take = 0;
        if(arr[ind] <= target) 
            take = f(ind-1, target-arr[ind], arr, dp);
        
        return dp[ind][target] = (notTake + take) % MOD;
    }
    
    int countPartitions(vector<int>& arr, int d) {
        int totSum = 0;
        for(int x : arr) totSum += x;
        
        if((totSum + d) % 2) return 0;
        int target = (totSum + d)/2;
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }
};





// tabulation : 
class Solution {
  public:
    const int MOD = 1e9+7;
    
    int countPartitions(vector<int>& arr, int d) {
        int totSum = 0;
        for(int x : arr) totSum += x;
        
        if((totSum + d) % 2) return 0;
        int target = (totSum + d)/2;
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        // base cases
        if(arr[0] == 0) dp[0][0] = 2;  // pick or not pick zero
        else dp[0][0] = 1;             // not pick
        
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        
        for(int ind=1; ind<n; ind++) {
            for(int sum=0; sum<=target; sum++) {
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(arr[ind] <= sum) take = dp[ind-1][sum-arr[ind]];
                dp[ind][sum] = (notTake + take) % MOD;
            }
        }
        
        return dp[n-1][target];
    }
};




// space optimization : 
class Solution {
  public:
    const int MOD = 1e9+7;
    
    int countPartitions(vector<int>& arr, int d) {
        int totSum = 0;
        for(int x : arr) totSum += x;
        
        if((totSum + d) % 2) return 0;
        int target = (totSum + d)/2;
        
        int n = arr.size();
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
        
        for(int ind=1; ind<n; ind++) {
            cur = prev;
            for(int sum=0; sum<=target; sum++) {
                int notTake = prev[sum];
                int take = 0;
                if(arr[ind] <= sum) take = prev[sum-arr[ind]];
                cur[sum] = (notTake + take) % MOD;
            }
            prev = cur;
        }
        
        return prev[target];
    }
};
