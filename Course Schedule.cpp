class Solution {
public:
    unordered_set<int> visitSet;
    bool dfs(int crs, vector<vector<int>>& preMap) {
        if (visitSet.count(crs))
            return false;
        if (preMap[crs].empty())
            return true;
        visitSet.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre, preMap))
                return false;
        }
        visitSet.erase(crs);
        preMap[crs].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        for (auto& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);
        }
        for (int crs = 0; crs < numCourses; crs++) {
            if (!dfs(crs, preMap))
                return false;
        }
        return true;
    }
};
