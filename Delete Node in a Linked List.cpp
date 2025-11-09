// Simple logic
class Solution {
public:
    void deleteNode(ListNode* node) {

        // node's value will directly point to it's next value 
        node->val = node->next->val; 
        // and node's next value will point to it's next to next value 
        node->next = node->next->next;
        
        
    }
};
