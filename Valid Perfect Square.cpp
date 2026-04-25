class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i = 0;
        while(i <= num){
            if(i * i == num){
                return true;
                break;
            }
            i++;
        }
        return false;
    }
};
