class Solution {
public:
    bool isPrime(int x){
        if(x < 2) return false;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0) return false;
        }
        return true;
    }

    int reverseNum(int n){
        int rev = 0;
        while(n > 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int r = reverseNum(n);

        int L = min(n, r);
        int R = max(n, r);

        int sum = 0;

        for(int i = L; i <= R; i++){
            if(isPrime(i)) sum += i;
        }

        return sum;
    }
};
