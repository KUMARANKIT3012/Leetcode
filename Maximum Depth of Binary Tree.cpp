// updated code 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return NULL;
        int lt = maxDepth(root->left);
        int rt = maxDepth(root->right);
        return 1 + max(lt , rt);
    }
};
