constexpr int N=1e6+2;
bitset<N> hasX, freq2;

class Solution {
public:
    static int maxSelectedElements(vector<int>& nums) {
        const int M=(ranges::max(nums)>>6)+1;
        memset(&hasX, 0, M<<3);
        memset(&freq2, 0, M<<3);

        for (int x : nums) {
            freq2[x]=hasX[x];
            hasX[x]=1;
        }

        int ans=0, prv=-3, dp0=0, dp1=0, xMax=M<<6;
        for (int x=hasX._Find_first(); x<=xMax+1; x=hasX._Find_next(x)) {
            switch (x-prv) {
                case 1:  dp0++; dp1++; break;
                case 2:  dp0=dp1+1; dp1=1; break;
                default: dp0=dp1=1; break;
            }
            if (freq2[x]) dp1=dp0+1;
            ans=max(ans, max(dp0, dp1));
            prv=x;
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
