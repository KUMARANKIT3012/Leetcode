class Solution {
public:
    string solve(int idx, vector<string>& nums, vector<char>& cur, unordered_set<string>& st) { 
        if (idx == nums.size()) {
            string res(cur.begin(), cur.end());
            if (st.find(res) == st.end()) {
                return res;
            }
            return "";
        }
        string res = solve(idx + 1, nums, cur, st);
        if (res != "") {
            return res;
        }
        cur[idx] = '1';
        res = solve(idx + 1, nums, cur, st);
        if (res != "") {
            return res;
        }
        cur[idx] = '0';
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {      
        unordered_set<string> st(nums.begin(), nums.end());
        vector<char> cur(nums.size(), '0');
        return solve(0, nums, cur, st);
    }
};
