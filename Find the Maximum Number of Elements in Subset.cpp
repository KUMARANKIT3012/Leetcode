class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (int x : nums) mp[x]++;
        int ans = 1;
        if (mp.count(1)) {
            if (mp[1] % 2 == 0)
                ans = max(ans, mp[1] - 1);
            else
                ans = max(ans, mp[1]);
        }
        for (auto it : mp) {
            long long x = it.first;
            if (x == 1) continue;
            int cnt = 0;
            long long cur = x;
            while (mp[cur] >= 2) {
                cnt += 2;
                if (cur > 1000000000)
                    break;
                cur = cur * cur;
            }
            if (mp[cur] == 1) cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
