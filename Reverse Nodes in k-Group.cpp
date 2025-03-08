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
    ListNode* reverselinkedlist(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newhead = reverselinkedlist(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

    ListNode* getkthnode(ListNode* temp, int k) {
        k -= 1;
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        
        while(temp != NULL) {
            ListNode* kthnode = getkthnode(temp, k);
            if(kthnode == NULL) {
                if(prevlast) prevlast->next = temp;
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            ListNode* newhead = reverselinkedlist(temp);
            if(temp == head) {
                head = newhead;
            } else {
                prevlast->next = newhead;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};
