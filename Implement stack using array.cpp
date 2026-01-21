class myStack {
    private:
    int *arr;
    int top;
    int size;
    
  public:
    myStack(int n) {
        // Define Data Structures
        size = n;
        arr = new int[n];
        top = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == -1;
    }

    bool isFull() {
        // check if the stack is full
        return top == size-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return;
        }
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
};
