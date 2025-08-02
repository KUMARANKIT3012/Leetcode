class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int newColor, int iniColor) {
        // Change the current pixel to the new color
        image[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        // Directions: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check bounds and if the pixel has the original color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && image[nrow][ncol] != newColor) {
                dfs(nrow, ncol, image, newColor, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if (iniColor != color) {
            dfs(sr, sc, image, color, iniColor);
        }
        return image;
    }
};
