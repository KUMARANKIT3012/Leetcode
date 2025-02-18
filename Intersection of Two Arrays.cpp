class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        vector<int> ans;

        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) {
                i++;
            } 
            else if (A[i] > B[j]) {
                j++;
            } 
            else {
                if (ans.empty() || ans.back() != A[i]) {
                    ans.push_back(A[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
