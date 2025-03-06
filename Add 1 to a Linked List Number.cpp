class Solution {
  public:
  
    int addhelper(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = addhelper(temp->next);
        temp-> data = temp->data + carry;
        if(temp->data < 10){
            return 0;
        }
        temp->data = 0;
        return 1;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry = addhelper(head);
        if(carry == 1){
            Node* newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }
        return head;
    }
};
