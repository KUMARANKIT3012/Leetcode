class Solution {
public:
    int addDigits(int num) {
        if(num == 0)return 0;
        int sum = 0;
        if(num % 9 == 0){
            sum = 9;
        }
        else{
            sum = num % 9;
        }
        return sum;
    }
};
