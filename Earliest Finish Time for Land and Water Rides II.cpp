class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur,
    vector<int>& Bstart, vector<int>& Bdur) {
        int m = Bstart.size();
        vector<pair<int,int>> b;

        for(int i = 0; i < m; i++) {
            b.push_back({Bstart[i], Bdur[i]});
        }

        sort(b.begin(), b.end());

        vector<long long> prefixMinDur(m), suffixMinFinish(m);

        prefixMinDur[0] = b[0].second;

        for(int i = 1; i < m; i++) {
            prefixMinDur[i] = min(prefixMinDur[i - 1],
            (long long)b[i].second);
        }

        suffixMinFinish[m - 1] =
            (long long)b[m - 1].first + b[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] = min(
                suffixMinFinish[i + 1],
                (long long)b[i].first + b[i].second
            );
        }

        vector<int> starts;

        for(auto &p : b) {
            starts.push_back(p.first);
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i < Astart.size(); i++) {

            long long finishA =
                (long long)Astart[i] + Adur[i];

            int idx = upper_bound(starts.begin(),
                starts.end(),
                finishA) - starts.begin();

            if(idx > 0) {
                ans = min(ans,
                finishA + prefixMinDur[idx - 1]);
            }

            if(idx < m) {
                ans = min(ans,
                suffixMinFinish[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        long long a =
            solve(landStartTime, landDuration,
            waterStartTime, waterDuration);

        long long b =
            solve(waterStartTime, waterDuration,
            landStartTime, landDuration);

        return min(a, b);
    }
};
