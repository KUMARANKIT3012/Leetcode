class Solution {
public:
    int cnt = 0;
    string ans = "";

    void solve(string &curr, vector<bool> &used, int n, int k) {
        if (curr.size() == n) {
            cnt++;
            if (cnt == k) ans = curr;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(i + '0');

                solve(curr, used, n, k);

                curr.pop_back();
                used[i] = false;

                if (ans != "") return;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<bool> used(n + 1, false);
        string curr = "";
        solve(curr, used, n, k);
        return ans;
    }
};
