class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: Move `prev` to the node just before the 'left' position
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = NULL;
        ListNode* tail = curr; // the node that will become the tail of the reversed part

        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        // Step 3: Connect the remaining part
        tail->next = curr;

        return dummy->next;
    }
};
