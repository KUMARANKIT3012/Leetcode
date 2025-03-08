// note : whenever u are doing this problem just remember that root is given not head so 'child' nahi hoga 'bottom' hoga

class Solution {
  public:
    Node* mergetwolist(Node* list1, Node* list2) {
        Node* dummynode = new Node(-1);  // Dummy node to simplify merging logic
        Node* res = dummynode;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
        }

        // Attach the remaining list if any
        if (list1) res->bottom = list1;
        else res->bottom = list2;

        Node* head = dummynode->bottom;  // Store head before deleting dummy
        delete dummynode;  // Prevent memory leak
        
        return head; // Returning the merged list
    }

    // Function which returns the root of the flattened linked list.
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) return root;

        // Flatten the rest of the list first
        root->next = flatten(root->next);
        
        // Merge the current list with the flattened list
        root = mergetwolist(root, root->next);
        
        // Ensure next pointer is NULL to maintain a flattened structure
        root->next = NULL;
        
        return root;
    }
};
