class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0&&j>=0){ // it should not be A[i] 
            if(A[i]>=B[j]){
                A[idx]=A[i];
                idx--;
                i--;
            }
            else{
                A[idx]=B[j];
                idx--;
                j--;
            }
        }
        while(j>=0){ // it should not be B[j]
            A[idx]=B[j];
            idx--;
            j--;
        }
    }
};
