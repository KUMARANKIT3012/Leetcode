class Solution {
public:

    bool validParenthesis(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l < r){
            if(s[l] != s[r]){
                return validParenthesis(s,l+1,r) || validParenthesis(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};
