class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){ // BASE CASE
            return n;
        }
        return fib(n-1) + fib(n-2); // MAIN RECURSIVE LOGIC
    }
};
