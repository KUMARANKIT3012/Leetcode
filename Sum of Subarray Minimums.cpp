class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> psee(n, -1), nse(n, n);
        stack<int> s;
        
        // Finding Previous Smaller or Equal Element (PSEE)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            psee[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clearing stack taaki reuse kar sake for (NSE)
        while (!s.empty()) s.pop();
        
        // Finding Next Smaller Element (NSE)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >arr[i]) {
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long count_left = i - psee[i];
            long long count_right = nse[i] - i;
            result = (result + arr[i] * count_left * count_right) % MOD;
        }
        
        return result;
    }
};
