class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int st = 0;
        int end = A.size()-1;
        while(st<end){
            int mid = st + (end - st)/2;
            if(mid % 2 == 1) mid--;
            if(A[mid] == A[mid+1]){
                st = mid+2;
            }
            else{
                end = mid;
            }
        }
        return A[st];
    }      
};
