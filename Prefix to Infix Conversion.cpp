class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;

        // last se first tak jaa 
        for (int i = pre_exp.size() - 1; i >= 0; i--) {
            char ch = pre_exp[i];

            if (isalnum(ch)) {  // If operand, push to stack
                st.push(string(1, ch));
            } else {  // If operator, pop two elements
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = "(" + op1 + ch + op2 + ")"; // different from postfix to infix
                st.push(temp); 
            }
        }

        return st.top();  
    }
};
