class MinStack {
public:
        stack<int> st;
        stack<int> minst;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(!minst.empty()){
            val = min(val, minst.top());
        }
        else{
            val = min(val, val);
        }
        minst.push(val);
    }
    
    void pop() {
        if(!st.empty() && !minst.empty()){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        else{
            return -1;
        }
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        else{
            return -1;
        }
    }
};
