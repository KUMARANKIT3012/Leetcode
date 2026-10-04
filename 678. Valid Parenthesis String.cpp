class Solution {
public:
    bool checkValidString(string s) {
        int open_count = 0, close_count =0;
        int len= s.length()-1;
        for(int i=0;i<=len;i++)
        {
            if(s[i] == '(' || s[i] == '*')
                open_count ++;
            else 
                open_count --;
            if(s[len-i] == ')' || s[len-i] == '*')
                close_count ++;
            else
                close_count --;
            if(open_count < 0 || close_count <0)
                return false;
        }
        return true;
    }
};
