class Solution {
  public:
  
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(Node* root, int index, int totalNodes) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        
        return isCBT(root->left, 2 * index + 1, totalNodes) &&
               isCBT(root->right, 2 * index + 2, totalNodes);
    }

    bool isMaxOrder(Node* root) {
        if (!root->left && !root->right) return true;
        
        if (root->right == NULL) {
            return (root->data >= root->left->data) && isMaxOrder(root->left);
        } else {
            return (root->data >= root->left->data &&
                    root->data >= root->right->data &&
                    isMaxOrder(root->left) &&
                    isMaxOrder(root->right));
        }
    }

    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        return isCBT(tree, 0, totalNodes) && isMaxOrder(tree);
    }
};
