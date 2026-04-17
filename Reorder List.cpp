class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //  reverse the second half 
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        slow->next = NULL;

        // merge the reversed linked list 
        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }



      /*
      🔹 Reorder Linked List – Key Notes
      Problem pattern
      → Alternating merge: first node, last node, second node, second last…
      3-step approach
      → Find middle → Reverse second half → Merge alternately
      Find middle technique
      → Use slow & fast pointers
      → Fast moves 2x, slow moves 1x
      Middle result
      → When loop ends, slow points to middle node
      
      Split the list (IMPORTANT)
      → Break using:
      
      slow->next = NULL;
      Reverse logic (core pattern)
      → Use 3 pointers: prev, curr, next
      Reversal result
      → prev becomes new head of second half
      Merging strategy
      → Alternate nodes from both halves (not sorted merge)
      
      Temporary pointers are crucial
      → Always store:
      
      temp1 = first->next;
      temp2 = second->next;
      
      → Prevent losing list
      
      Complexity
      → Time: O(n)
      → Space: O(1) (in-place)
            
      */

    }
};
