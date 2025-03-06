class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        
        if(!head || !head->next) return head;
        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead = new Node(-1);
        
        Node* zero = zerohead;
        Node* one = onehead;
        Node* two = twohead;
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (onehead->next) ? (onehead->next) : (twohead->next);
        one->next = twohead->next;
        two->next = NULL;
        
        Node* newhead = zerohead->next;
        
        delete zerohead;
        delete onehead;
        delete twohead;
        return newhead;
    }
};
