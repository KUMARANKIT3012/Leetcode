class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpathdown(root, maxi);
        return maxi;
    }

    int maxpathdown(TreeNode* node, int &maxi){
        if(node == NULL) return 0;
        int left = max(0, maxpathdown(node->left, maxi));
        int right = max(0, maxpathdown(node->right, maxi));
        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};
