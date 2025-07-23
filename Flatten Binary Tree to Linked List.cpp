class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        // Step 1: Recursively flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Step 2: Store left and right subtrees
        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        // Step 3: Attach the left subtree to the right
        root->left = NULL;
        root->right = leftSubtree;

        // Step 4: Move to the end of the new right subtree
        TreeNode* temp = root;
        while (temp->right != NULL) {
            temp = temp->right;
        }

        // Step 5: Attach the previously stored right subtree
        temp->right = rightSubtree;
    }
};
