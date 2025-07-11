class Solution {
public:
    void postorder(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
            return;

        postorder(node->left, result);      // Left
        postorder(node->right, result);     // Right
        result.push_back(node->val);        // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
