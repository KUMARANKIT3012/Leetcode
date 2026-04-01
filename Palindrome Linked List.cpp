class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // find middle
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse second half
        ListNode* prev = NULL;
        while (slow) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // check palindrome
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
