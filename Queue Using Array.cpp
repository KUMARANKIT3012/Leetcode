void MyQueue::push(int x) {
    arr[rear] = x;  // Insert element at the end
    rear++;  // Move rear by one place
}
int MyQueue::pop() {
    if (front == rear) {  // If queue is empty
        return -1;
    }

    int el = arr[front];  // take the front element
    front++;  // Move the front pointer forward

    return el;
}
