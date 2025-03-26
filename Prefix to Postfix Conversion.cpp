class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        int n = pre_exp.length();

        for (int i = n - 1; i >= 0; i--) { // Traverse in reverse
            char ch = pre_exp[i];
            if (isalnum(ch)) { // Operand
                st.push(string(1, ch));
            } else { // Operator
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = op1 + op2 + ch; // Convert to postfix
                st.push(temp);
            }
        }

        return st.top();
    }
};
