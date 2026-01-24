class Node {
    
    
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    
    private:
    Node* frontnode;
    Node* rearnode;
    int cnt;

  public:
    myQueue() {
        // Initialize your data members
        frontnode = nullptr;
        rearnode = nullptr;
        cnt = 0;
        
    }

    bool isEmpty() {
        // check if the queue is empty
        return frontnode == nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newnode = new Node(x);
        if(isEmpty()){
            frontnode = rearnode = newnode;
        }
        else{
            rearnode->next = newnode;
            rearnode = newnode;
        }
        cnt++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        
        Node* temp = frontnode;
        frontnode = frontnode->next;
        
        if(frontnode == nullptr){
            rearnode = nullptr;
        }
        delete temp;
        cnt--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return frontnode->data;
    }

    int size() {
        // Returns the current size of the queue.
        return cnt;
    }
};
