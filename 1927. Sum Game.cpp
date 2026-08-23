class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int lsum = 0, rsum = 0, qleft = 0, qright = 0;

        for(int i = 0; i<n/2; i++){
            if(num[i] == '?') qleft++;
            else lsum += num[i] - '0';
        }

        for(int i = n/2; i<n; i++){
            if(num[i] == '?') qright++;
            else rsum += num[i] - '0';
        }

        return 2 * (lsum - rsum) != 9 * (qright - qleft);

    }
};
