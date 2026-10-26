class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                int top = st.top();
                if(st.empty()) return false;
                else if(top == '(' && c == ')' ||
                        top == '{' && c == '}' ||
                        top == '[' && c == ']'){
                            st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
