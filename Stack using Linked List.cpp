/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    private:
    Node* topnode;
    int cnt;

  public:
    myStack() {
        // Initialize your data members
        topnode = nullptr;
        cnt = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return topnode == nullptr;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newnode = new Node(x);
        newnode->next = topnode;
        topnode = newnode;
        cnt++;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty()) return;
        
        Node* temp = topnode;
        topnode = topnode->next;
        delete temp;
        cnt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()) return -1;
        return topnode->data;
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};
