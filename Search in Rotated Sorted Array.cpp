class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st=0, end=A.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(A[mid]==tar){
                return mid;
            }
            if(A[st]<=A[mid]){ // check for which side is rotated 
                if(A[st]<=tar && tar<=A[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                if(A[mid]<=tar && tar<=A[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
