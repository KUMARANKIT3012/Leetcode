class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k){
        int n = arr.size();
        int count = 0;
        int noofb = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] <= day){
                count++;
            } else {
                noofb += (count / k);
                count = 0;
            }
        }
        noofb += (count / k);
        return noofb >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long total = 1LL * m * k;
        if(arr.size() < total) return -1;  // not enough flowers (edge case hai)
        
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(arr, mid, m, k)){
                ans = mid;
                high = mid - 1;  // try to minimize
            } else {
                low = mid + 1;   // need more days
            }
        }

        return ans;
    }
};
