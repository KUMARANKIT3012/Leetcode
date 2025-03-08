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
    ListNode* findnthnode(ListNode* temp, int k){
        int count = 1;
        while(temp != NULL){
            if(count == k) return temp;
            count++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail -> next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k%len == 0) return head;

        k= k%len;

        // attach the tail to head:
        tail->next = head;
        ListNode* newlastnode = findnthnode(head, len-k);

        head = newlastnode->next;
        newlastnode->next = NULL;
        return head;
    }
};
