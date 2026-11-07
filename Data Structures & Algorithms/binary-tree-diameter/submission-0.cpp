
class Solution {
public:
    int maxEdges = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        maxEdges = max(l + r, maxEdges);
        return 1 + max(l,r) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxEdges;
    }
};