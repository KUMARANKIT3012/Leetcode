class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];

                ListNode* list2 = (i + 1 < lists.size())
                                   ? lists[i + 1]
                                   : NULL;

                mergedLists.push_back(mergeTwoLists(list1, list2));
            }

            lists = mergedLists;
        }

        return lists[0];
    }
};
