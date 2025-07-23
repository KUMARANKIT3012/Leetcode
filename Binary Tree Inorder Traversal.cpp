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

// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = cur;  // Threading
                    cur = cur->left;
                } else {
                    prev->right = NULL;  // Remove thread
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }
};

