class Solution {
public:
    int Height(TreeNode* root, int& diameter){
        if(!root) return NULL;
        int lh = Height(root->left, diameter);
        int rh = Height(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        Height(root, diameter);
        return diameter;
    }
};
