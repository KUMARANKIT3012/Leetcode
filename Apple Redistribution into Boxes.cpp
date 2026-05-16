class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;

        for (int x : apple) {
            totalApples += x;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;
        int current = 0;

        for (int cap : capacity) {
            current += cap;
            boxes++;

            if (current >= totalApples) {
                return boxes;
            }
        }

        return boxes;
    }
};
