class Solution {
public:
    void preorder(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
            return;

        result.push_back(node->val);        // Root
        preorder(node->left, result);       // Left
        preorder(node->right, result);      // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};
