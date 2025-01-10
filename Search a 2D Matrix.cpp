class Solution {
public:
    bool searchinrow(vector<vector<int>>& mat, int target, int row){ //O(logn)
        int n=mat[0].size();
        int st=0, end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target==mat[row][mid]){
                return true;
            }
            else if(target > mat[row][mid]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) { //O(log m)
        // BS on total rows:
        int m=mat.size(), n=mat[0].size();
        int startrow=0, endrow= m-1;
        while(startrow<=endrow){
            int midrow = startrow + (endrow-startrow)/2;

            if(target >= mat[midrow][0] && target <= mat[midrow][n-1]){
                // found the row ==> BS on this row:
                return searchinrow(mat,target,midrow);
            }
            else if(target >= mat[midrow][n-1]){
                //down ==> right:
                startrow=midrow+1;
            }
            else{
                // up ==> left:
                endrow= midrow-1;
            }
        }
        return false;
    }
};
