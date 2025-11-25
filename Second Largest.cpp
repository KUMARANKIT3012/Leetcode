class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = arr[0];
        int seclargest = INT_MIN;
        int n = arr.size();
        for(int i = 1;i<n; i++){
            if(largest < arr[i]){
                seclargest = largest;
                largest = arr[i];
            }
            else if(largest > arr[i] && arr[i] > seclargest){
                seclargest = arr[i];
            }
        }
        if(seclargest == INT_MIN){
            return -1;
        }
        return seclargest;
    }
};
