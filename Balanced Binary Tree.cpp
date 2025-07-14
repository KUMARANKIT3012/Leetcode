class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    int check(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = check(root->left);
        if(lh == -1) return -1; // just add this  ---> rest all code is same as checking the height of the binary tree 
        int rh = check(root->right);
        if(rh == -1) return -1; // just add this

        if(abs(lh-rh)>1)return -1; // just add this

        return max(lh , rh) +1;
    }
};
