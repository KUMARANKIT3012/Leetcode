class MinStack {
private:
    std::stack<long long> st;  // Use long long to prevent overflow
    long long minElement;  

public:
    MinStack() {
        minElement = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            minElement = val;
            st.push(val);
        } else {
            if (val >= minElement) {
                st.push(val);
            } else {
                st.push(2LL * val - minElement);  // Use long long to avoid overflow
                minElement = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < minElement) {
            minElement = 2 * minElement - x;  // No risk of overflow here
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long x = st.top();
        return (x < minElement) ? minElement : x;
    }
    
    int getMin() {
        return (st.empty()) ? -1 : minElement;
    }
};
