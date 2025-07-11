class Solution {
public:
    void inorder(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
            return;

        inorder(node->left, result);         // Left
        result.push_back(node->val);         // Root
        inorder(node->right, result);        // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
