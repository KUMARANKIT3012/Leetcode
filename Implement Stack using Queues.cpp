class MyStack {
private:
std::vector<int> stack;
public:
    MyStack() {
    }
    void push(int x) {
        stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty()){
            return -1;
        }
        int topelement = stack.back();
        stack.pop_back();
        return topelement;
        
    }
    
    int top() {
        if(stack.empty()) return -1;
        return stack.back();
        
    }
    
    bool empty() {
        return stack.empty();
        
    }
};
