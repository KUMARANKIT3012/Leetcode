class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;

        for (char ch : exp) {
            if (isalnum(ch)) {  // If operand, push to stack
                st.push(string(1, ch)); // CONVERT KAR CHAR TO STRING
            } else {  // If operator, pop two elements
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = "(" + op1 + ch + op2 + ")";
                st.push(temp);
            }
        }

        return st.top();
    }
};
