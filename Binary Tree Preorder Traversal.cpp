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



// via iterative approach :
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();

            preorder.push_back(root->val);
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left != NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};


