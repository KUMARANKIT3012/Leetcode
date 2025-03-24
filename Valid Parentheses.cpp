class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c); // push open bracket
            }
            else{
                if(st.empty()) return false;
                char top = st.top();
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop(); // pop matching bracket
                }
                else{
                    return false; 
                }
            }
        }
        return st.empty();
    }
};
