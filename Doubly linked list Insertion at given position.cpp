class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node *newnode = new Node(data);
        Node* temp = head;
        
        for(int i=0; i<pos; i++){
            if(temp->next == NULL){
                break;
            }
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        newnode->prev = temp;
        
        if(temp->next){
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        
        return head;
    }
};
