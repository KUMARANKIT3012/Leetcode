class Solution {
public:
    unordered_set<int> visit, cycle;
    vector<int> output;
    bool dfs(int crs, vector<vector<int>>& prereq) {
        if (cycle.count(crs))
            return false;
        if (visit.count(crs))
            return true;
        cycle.insert(crs);
        for (int pre : prereq[crs]) {
            if (dfs(pre, prereq) == false)
                return false;
        }
        cycle.erase(crs);
        visit.insert(crs);
        output.push_back(crs);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq(numCourses);
        for (auto& p : prerequisites) {
            int crs = p[0];
            int pre = p[1];
            prereq[crs].push_back(pre);
        }
        for (int c = 0; c < numCourses; c++) {
            if (dfs(c, prereq) == false)
                return {};
        }
        return output;
    }
};
