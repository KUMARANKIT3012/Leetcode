// ultimate solution without stack and with recursion using inorder traversal : 
class Solution {
public:
    int ans;

    void inorder(TreeNode* root, int& k){
        if(root == NULL) return;

        inorder(root->left, k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }

private:
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (node == nullptr) return;

        inorder(node->left, k, count, result);
        
        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        inorder(node->right, k, count, result);
    }
};




// iteratively : 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {

            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            n++;

            if (n == k) {
                return cur->val;
            }

            cur = cur->right;
        }

        return -1;
    }
};
