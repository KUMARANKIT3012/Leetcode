class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
