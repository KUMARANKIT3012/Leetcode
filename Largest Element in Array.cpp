class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largest = INT_MIN;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        return largest;
    }
};
