class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL){
            ListNode* firstnext = first->next;
            ListNode* secondnext = second->next;

            first->next = second;
            second->next = firstnext;

            first = firstnext;
            second = secondnext;
        }
    }
};
