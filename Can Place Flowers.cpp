class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool prev = true;
                if (i > 0 && flowerbed[i - 1] == 1) {
                    prev = false;
                }
                bool next = true;
                if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) {
                    next = false;
                }
                if (prev && next) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};
