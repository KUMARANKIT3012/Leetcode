class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;

        for(char c : s){
            if(c == '1') count++;
        }

        return string(count - 1, '1') + string(s.length() - count, '0') + '1';
    }
};
