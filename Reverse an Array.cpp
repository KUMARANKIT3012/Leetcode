class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size()-1;
        int st = 0;
        int end = n;
        while(st<=end){
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }
};
