class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        string converted = "";
        for(char ch : s) {
            converted += to_string(ch - 'a' + 1);
        }

        int sum = 0;
        for(char ch : converted) {
            sum += ch - '0';
        }
        k--;
        
        while(k--) {
            sum = digitSum(sum);
        }

        return sum;
    }
};
