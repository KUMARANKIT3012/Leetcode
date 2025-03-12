class Solution {
public:
    void findcombination(vector<int>& arr, int idx, int target, vector<vector<int>> &ans, vector<int> &ds) {
        // Base case: 
        if (idx == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick up the element if it does not exceed the target
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findcombination(arr, idx, target - arr[idx], ans, ds); // Recursive call with the same index
            ds.pop_back(); // Backtracking step
        }

        // Move to the next index
        findcombination(arr, idx + 1, target, ans, ds);
    }    

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(candidates, 0, target, ans, ds);
        return ans;
    }
};
