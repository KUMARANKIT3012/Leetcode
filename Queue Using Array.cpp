class myQueue {

private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    myQueue(int n) {
        size = n;
        arr = new int[n];
        front = -1;   // -1 means queue is empty
        rear = -1;
    }

    bool isEmpty() {
        // Queue is empty when front is -1
        return front == -1;
    }

    bool isFull() {
        // Queue is full if next position of rear is front
        // This means no free space is left
        return ( (rear + 1) % size == front );
    }

    void enqueue(int x) {
        // Adds element at rear

        if (isFull()) {
            return; // overflow
        }

        // If first element is being inserted
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // Move rear circularly
            rear = (rear + 1) % size;
        }

        arr[rear] = x; // insert element
    }

    void dequeue() {
        // Removes front element

        if (isEmpty()) {
            return; // underflow
        }

        // If only one element was present
        if (front == rear) {
            // Queue becomes empty after deletion
            front = -1;
            rear = -1;
        } else {
            // Move front circularly
            front = (front + 1) % size;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
};
