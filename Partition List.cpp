class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);

        ListNode* ltail = left;
        ListNode* rtail = right;

        while(head != NULL){

            if(head->val < x){
                ltail->next = head;
                ltail = ltail->next;
            }
            else{
                rtail->next = head;
                rtail = rtail->next;
            }

            head = head->next;
        }

        ltail->next = right->next;
        rtail->next = NULL;

        return left->next;
    }
};
