class Solution {
  public:
    int factorial(int n) {
        // code here
        if (n == 0 || n == 1) return 1;
        
        return n * factorial(n-1);
    }
};
