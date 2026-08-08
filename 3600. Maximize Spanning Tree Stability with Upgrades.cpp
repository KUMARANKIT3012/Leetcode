class Solution {
public:
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        p[a] = b;
        return true;
    }

    bool check(int n, vector<vector<int>>& edges, int k, int x) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);

        int cnt = 0;

        // Mandatory edges
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int s = e[2], must = e[3];

            if (must) {
                if (s < x || !unite(u, v))
                    return false;

                cnt++;
            }
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int s = e[2], must = e[3];

            if (!must && s >= x) {
                if (unite(u, v))
                    cnt++;
            }
        }

        int used = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int s = e[2], must = e[3];

            if (!must && s < x && 2 * s >= x) {
                if (unite(u, v)) {
                    cnt++;
                    used++;

                    if (used > k)
                        return false;
                }
            }
        }

        return cnt == n - 1 && used <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 1, hi = 200000, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
