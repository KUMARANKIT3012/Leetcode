/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second= head;
        ListNode* curr = head;
        for(int i = 1; i<k; i++){
            curr = curr->next;
        }

        first = curr;

        while(curr->next != nullptr){
            curr = curr->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};
