class Solution {
  public:
    int precedence(char c){
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return 0;
    }
    public:
    string infixToPostfix(string& s){
        stack<char>st;
        string ans = "";
        
        for(char c : s){
            if(isalnum(c)){
                ans+= c;
            }
            else if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+= st.top();
                    st.pop();
                }
                st.pop(); // remove '(' from stack
            }
            else{
                while(!st.empty() && precedence(st.top()) >= precedence(c)){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
