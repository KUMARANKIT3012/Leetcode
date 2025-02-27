class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node *newnode = new Node(x);
        if(head == NULL){
            return newnode;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
};
