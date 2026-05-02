class Solution {
public:

int countpali(string &s, int l, int r){
    int count = 0;

    while(l >= 0 && r<s.length() && s[l] == s[r]){
        count++;
        l--;
        r++;
    }
    return count;
}
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i<s.length(); i++){
        // odd palindrome ke liye 
        res += countpali(s, i, i);

        // even palindrome ke liye 
        res += countpali(s, i , i+1);
        }

        return res;
    }
};
