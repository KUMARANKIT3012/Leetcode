class Solution {
public:
    int Check(TreeNode* root){
        if(!root) return NULL;
        int lh = Check(root->left);
        if(lh == -1) return -1;
        int rh = Check(root->right);
        if(rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return Check(root) != -1;
    }
};
