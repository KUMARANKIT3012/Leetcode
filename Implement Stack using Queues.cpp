class MyStack {
private:
std::vector<int> stack;
public:
    MyStack() {
    }
     void push(int x) {
        stack.push_back(x); // Push at the end
    }
    
    int pop() {
        if (stack.empty()) return -1; // edge case hai yeh
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }
    
    int top() {
        if (stack.empty()) return -1; // empty stack condn
        return stack.back();
    }
    
    bool empty() {
        return stack.empty(); 
    }
};
