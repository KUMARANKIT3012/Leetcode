// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int maxcount = -1;
        int index = -1;
        for(int i = 0; i<n; i++){
            int countrow = 0;
            for(int j = 0 ;j<m; j++){
                countrow+=arr[i][j];
            }
            if(countrow > maxcount){
                maxcount = countrow;
                index = i;
            }
            
        }
        return index;
    }
};
