class Solution {
  public:
  
  int precedence(char c){
      if(c == '^') return 3;
      if(c == '*' || c == '/') return 2;
      if(c == '+' || c == '-') return 1;
      return 0;
  }
  
  string infixToPostfix(string& s) {
      stack<char> st;
      string ans = "";
      
      for(char c : s){
          // If operand, add to answer
          if(isalnum(c)){
              ans += c;
          }
          // If '(', push to stack
          else if(c == '('){
              st.push(c);
          }
          // If ')', pop until '('
          else if(c == ')'){
              while(!st.empty() && st.top() != '('){
                  ans += st.top();
                  st.pop();
              }
              st.pop(); // pop '('
          }
          // If operator
          else{
              while(!st.empty() && 
                   (precedence(st.top()) > precedence(c) || 
                   (precedence(st.top()) == precedence(c) && c != '^'))){
                  ans += st.top();
                  st.pop();
              }
              st.push(c);
          }
      }
      
      // Pop remaining operators
      while(!st.empty()){
          ans += st.top();
          st.pop();
      }
      
      return ans;
  }
};
