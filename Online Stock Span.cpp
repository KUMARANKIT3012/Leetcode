class StockSpanner {
private:
    stack<pair<int, int>> st; // Stack stores (price, span)

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1; // Default span is 1 (itself)
        
        // Pop elements while the stack has a price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Accumulate span of popped elements
            st.pop();
        }
        
        // Push the current price with its span
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
