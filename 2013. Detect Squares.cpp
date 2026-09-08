class DetectSquares {
public:
    map<pair<int, int>, int> freq;
    map<int, vector<int>> ys;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        freq[{x, y}]++;
        ys[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (int y2 : ys[x]) {
            if (y2 == y) continue;
            int side = abs(y2 - y);
            ans += freq[{x + side, y}] * freq[{x + side, y2}];
            ans += freq[{x - side, y}] * freq[{x - side, y2}];
        }
        return ans;
    }
};
