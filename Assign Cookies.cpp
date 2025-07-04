class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int i = 0, j = 0;
        int contentChildren = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                // Cookie satisfies the child
                contentChildren++;
                i++;
                j++;
            } else {
                // Cookie too small, try next larger cookie
                j++;
            }
        }
        return contentChildren;
    }
};
