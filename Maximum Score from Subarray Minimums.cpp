class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        if (arr.size() < 2) return -1; // Not enough elements to form a pair
        
        int maxsum = INT_MIN;
        
        for(int i = 0; i < arr.size() - 1; i++) {
            maxsum = max(maxsum, arr[i] + arr[i + 1]);
        }
        
        return maxsum;
    }
};
