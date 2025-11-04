// Main logic is here : 
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if (*head_ref == NULL) return;  // Edge case: Empty list

        Node* temp = *head_ref;

        while (temp != NULL) {
            if (temp->data == x) {
                Node* nextnode = temp->next;
                Node* prevnode = temp->prev;

                // If the node to delete is the head node
                if (temp == *head_ref) {
                    *head_ref = nextnode;  // Update head reference
                }

                // Adjust the previous and next pointers
                if (nextnode) nextnode->prev = prevnode;
                if (prevnode) prevnode->next = nextnode;

                delete temp;  // Free memory
                temp = nextnode;  // Move to the next node
            } 
            else {
                temp = temp->next;
            }
        }
    }
};
