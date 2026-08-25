class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());
        int candidate = k;
        while (present.count(candidate)) {
            candidate += k;
        }
        return candidate;
    }
};
