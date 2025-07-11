class Solution {
public:
    void dfs(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        result.push_back(root->val);     // Visit root
        dfs(root->left, result);         // Traverse left subtree
        dfs(root->right, result);        // Traverse right subtree
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};
