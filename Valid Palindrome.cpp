class Solution {
public:
    bool isAlphaNum(char c){
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <='9');
    }

    bool isPalindrome(string s) {
        int l = 0;
        int n = s.length();
        int r = n-1;
        while(l < r){
            if(l < r && !isAlphaNum(s[l])){
                l++;
                continue;
            }
            else if(l < r && !isAlphaNum(s[r])){
                r--;
                continue;
            }
            else if(l < r && tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }    
};
