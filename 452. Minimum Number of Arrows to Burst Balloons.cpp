class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>>p;
        for(int i = 0; i<n; i++){
            p.push_back({points[i][1], points[i][0]});
        }
        sort(p.begin(), p.end());

        int count = 1;
        int lastfinish = p[0].first;

        for(int i = 1; i<n; i++){
            int currentstart = p[i].second;
            int currentfinish = p[i].first;
            if(currentstart > lastfinish){
                count++;
                lastfinish = currentfinish;
            }
        }
        return count;
    }
};
