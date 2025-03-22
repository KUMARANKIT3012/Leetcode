class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* newnode = new StackNode(x);
        newnode->next = top;
        top = newnode;
    }

    int pop() {
        // code here
        if (top == NULL) {
            return -1; 
        }

        int poppedValue = top->data;
        StackNode* temp = top;
        top = top->next; // Move top to the next node
        delete temp;
        return poppedValue;
    }

    MyStack() { top = NULL; }
};
