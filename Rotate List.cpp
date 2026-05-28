class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int length = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            length++;
        }
        k = k % length;
        if(k == 0){
            return head;
        }
        ListNode* curr = head;
        for(int i = 0; i < length - k - 1; i++){
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;
        tail->next = head;
        return newHead;
    }
};
