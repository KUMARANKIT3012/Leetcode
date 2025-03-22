void MyStack ::push(int x) {
    top = top + 1;
    arr[top] = x;
}

int MyStack ::pop() {
    if (top == -1) {
        return -1;
    } 
    return arr[top--];
}
