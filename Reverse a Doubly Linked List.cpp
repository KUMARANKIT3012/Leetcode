class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head == NULL) return NULL;
        
       DLLNode* temp = NULL;
       DLLNode* curr = head;
       
       while(curr != NULL){
           temp = curr->prev;
           curr->prev = curr->next;
           curr->next = temp;
           curr = curr->prev;
       }
       if(temp != NULL) head = temp->prev;
       return head;
    }
};




// OR


/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;  // store next node
            curr->next = prev;  // reverse current node's pointer
            prev = curr;        // move prev one step ahead
            curr = next;        // move curr one step ahead
        }
        
        return prev;  // new head
    }
};

