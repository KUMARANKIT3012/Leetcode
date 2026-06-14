class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maxi = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            maxi = max(maxi, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};
