class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) {
            vec.push_back({nums[i], i});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int> ans(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            while (j < n && vec[j].first - vec[j-1].first <= limit) {
                j++;
            }
            
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(vec[k].second);
            }
            
            sort(indices.begin(), indices.end());
            
            for (int k = 0; k < indices.size(); ++k) {
                ans[indices[k]] = vec[i + k].first;
            }
            
            i = j;
        }
        
        return ans;
    }
};
