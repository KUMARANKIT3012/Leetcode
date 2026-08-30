class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int a : nums){
            mp[a]++;
        }

        vector<pair<int, int>>ans;
        for(const auto &p : mp){
            ans.push_back({p.second, p.first});
        }

        sort(ans.rbegin(), ans.rend());
        vector<int>res;
        for(int i = 0; i<k; i++){
            res.push_back(ans[i].second);
        }

        return res;
    }
};
