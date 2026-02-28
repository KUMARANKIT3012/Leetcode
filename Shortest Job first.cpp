// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(), bt.end());
        
        long long currtime = 0;
        long long totalwait  = 0;
        for(int i = 0; i<n; i++){
            totalwait += currtime;
            currtime += bt[i];
        }
        return totalwait/n;
        
    }
};
