class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int row=0, col=n-1;
        while(col>=0 && row<m){
            if(target == mat[row][col]){
                return true;
            }
            else if(target < mat[row][col]){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};
