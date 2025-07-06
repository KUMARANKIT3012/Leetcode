class Solution {
public:
    int solve(int ind, vector<int>& nums) {
        int n = nums.size();
        if (ind >= n - 1) return 0; // already at or beyond last index

        int minJumps = INT_MAX;

        for (int jump = 1; jump <= nums[ind]; jump++) {
            int next = solve(ind + jump, nums);
            if (next != INT_MAX)
                minJumps = min(minJumps, 1 + next);
        }

        return minJumps;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};
