class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        int carry = 0;

        while(l1 || l2 || carry){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;

            cur->next = new ListNode(val);

            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy->next;
    }
};
