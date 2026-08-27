class MinStack {
public:
        stack<int>st;
        stack<int>minst;
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
        if(!minst.empty() && !st.empty()){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(minst.empty()){
            return -1;
        }
        return minst.top();
    }
};
