class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Update the height array
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') 
                    heights[j] += 1;
                else 
                    heights[j] = 0;  // Reset kardo agar '0' aa jaye
            }

            // Compute the largest rectangle using the histogram approach
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};





// DP - 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> height(cols, 0);
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            int curLeft = 0, curRight = cols;

            // 1. Update heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // 2. Update left boundaries
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // 3. Update right boundaries
            for (int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else {
                    right[j] = cols;
                    curRight = j;
                }
            }

            // 4. Compute area
            for (int j = 0; j < cols; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};

