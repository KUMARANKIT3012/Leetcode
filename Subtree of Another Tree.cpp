class Solution {
public:
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (s && t && s->val == t->val) {
            return sameTree(s->left, t->left) &&
            sameTree(s->right, t->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
        isSubtree(root->right, subRoot);
    }
};



// optimized way of solving this : 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sametree(TreeNode* s, TreeNode* t){
        if(s == NULL || t == NULL){
            return s == t;
        }

        return (s->val == t->val) && sametree(s->left, t->left) && sametree(s->right, t->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(!subRoot) return true;

        if(sametree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
