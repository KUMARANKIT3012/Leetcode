class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int findlength(Node * slow, Node * fast){
        int count = 1;
        fast = fast->next;
        while(slow != fast){
            count++;
            fast= fast->next;
        }
        return count;
    }

// MAIN FUNCTION : 
    int countNodesinLoop(Node *head) {
        // Code here
        Node * slow = head;
        Node * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return findlength(slow, fast);
            }
        }
        return 0;
    }
};
