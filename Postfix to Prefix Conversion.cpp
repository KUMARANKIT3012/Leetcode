class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> st;

        for (char ch : post_exp) {
            if (isalnum(ch)) {  // If operand the push 
                st.push(string(1, ch)); // convert to string
            } else {  // If operator pop two elt
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = ch + op1 + op2; // main logic 
                st.push(temp);
            }
        }

        return st.top(); 
    }
};
