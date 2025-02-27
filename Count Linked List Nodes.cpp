class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        // Code here
        int count = 0;
        Node* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
};
