class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(temp != 0){
            int dig = temp%10;
            sum += dig;
            prod *= dig;
            temp /= 10;
        }
        // if(n % sum != 0) return false;
        int total = sum + prod;
        // // if n % total == 0 ? return true : return false;
        // if(temp % total == 0) return true;
        // else return false;
        return n % (total) == 0;
    }
};
