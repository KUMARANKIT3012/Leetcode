void MyQueue:: push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    
    if (rear == NULL) { // If the queue is empty
        front = rear = newNode;
        return;
    }
    rear->next = newNode; // Link the last node to the new node
    rear = newNode;       // Update rear
}

int MyQueue :: pop()
{
    if (front == NULL) { // If queue is empty
    return -1; 
    }
    
    int poppedValue = front->data;
    QueueNode* temp = front;
    front = front->next; // Move front to the next node

    if (front == NULL) { 
        rear = NULL;
    }

    delete temp; // Free memory
    return poppedValue;
}
