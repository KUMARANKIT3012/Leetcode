class Solution {
public:
    vector<int> generaterows(int row){
        long long ans =1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int col = 1; col<row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        // int n = numRows.size();
        vector<vector<int>> ans;
        // vector<vector<int>> temp;
        for(int i = 1; i<=numRows; i++){
            ans.push_back(generaterows(i));
        }
        return ans;
    }
};
