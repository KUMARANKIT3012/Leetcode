class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ts;
        stack<char> ss;
        for(char c : s){
            if(c == '#'){
                if(!ss.empty()) ss.pop();
            }
            else ss.push(c);

        }
        for(char c : t){
            if(c == '#'){
                if(!ts.empty()) ts.pop();
            }
            else ts.push(c);
        }

        return ss == ts;
    }
};
