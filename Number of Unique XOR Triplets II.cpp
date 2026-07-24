class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<char> dp1(MAXX, 0), dp2(MAXX, 0), dp3(MAXX, 0);
        for (int v : vals) {
            vector<char> ndp3 = dp3;
            vector<char> ndp2 = dp2;
            for (int x = 0; x < MAXX; x++) {
                if (dp2[x]) ndp3[x ^ v] = 1;
                if (dp1[x]) ndp2[x ^ v] = 1;
            }
            dp3.swap(ndp3);
            dp2.swap(ndp2);
            dp1[v] = 1;
        }
        int ans = 0;
        for (int x = 0; x < MAXX; x++) {
            if (dp1[x] || dp3[x]) ans++;
        }
        return ans;
    }
};
