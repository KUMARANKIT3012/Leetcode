class Solution {
public:
    void nextPermutation(vector<int>& A) {
        // 1) find the pivot:
        int pivot=-1;
        int n=A.size();
        for(int i=n-2; i>=0; i--){
            if(A[i]<A[i+1]){
                pivot=i;
                break;
            }
        }
        // edge case:
        if(pivot == -1){
            reverse(A.begin(),A.end());
            return;
        }

        // 2) next larger eliment:
        for(int i=n-1; i>=0; i--){
            if(A[i]>A[pivot]){
                swap(A[i],A[pivot]);
                break;
            }
        }

        // 3) reverse (pivot-1 to n-1):
        int i=pivot+1;
        int j=n-1;
        while(i<=j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
};
