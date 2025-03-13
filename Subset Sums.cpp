class Solution {
  public:
    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& sumsubset) {
        // Base case:
        if (ind == arr.size()) {
            sumsubset.push_back(sum);
            return;
        }

        // Pick the element:
        func(ind + 1, sum + arr[ind], arr, arr.size(), sumsubset);

        // Do not pick the element:
        func(ind + 1, sum, arr, arr.size(), sumsubset);
    }

  public:
    vector<int> subsetSums(vector<int>& arr, int N) {
        // Code here
        vector<int> sumsubset;
        func(0, 0, arr, arr.size(), sumsubset);
        sort(sumsubset.begin(), sumsubset.end()); // Return in sorted manner
        return sumsubset;
    }
};
