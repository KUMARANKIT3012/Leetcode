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



// iterative approach using stack : 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};
