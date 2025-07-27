class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        Node* successor = NULL;
        
        // Case 1: If x has a right subtree
        if (x->right != NULL) {
            Node* temp = x->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            return temp->data;
        }

        // Case 2: No right subtree → Search from root
        while (root != NULL) {
            if (x->data < root->data) {
                successor = root;
                root = root->left;
            } else if (x->data >= root->data) {
                root = root->right;
            }
        }

        return (successor != NULL) ? successor->data : -1; // if no successor exists
    }
};
