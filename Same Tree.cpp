class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return (p == q);
        }
        return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right , q->right);
    }
};
