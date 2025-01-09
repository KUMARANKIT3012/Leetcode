class Solution {
public:
    int reverse(int n) {
        int revnum=0;
        while(n!=0){
            int dig=n%10;
            if(revnum > INT_MAX/10 || revnum < INT_MIN/10){
                return 0;
            }
            revnum=revnum*10+dig;
            n=n/10;
        }
        return revnum;
    }
    bool isPalindrome(int n) {
        if(n < 0) return false;

        int revnum=reverse(n);
        return n==revnum;
    }
};
