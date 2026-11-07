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
    bool balanced = true;
    int maxDepth(TreeNode* root){

        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if(balanced) balanced = abs(l - r) <= 1;
        
        if(balanced) return 1 + max(l,r);

        return -1;
        
    }
    bool isBalanced(TreeNode* root) {
        
        maxDepth(root);
        return balanced;
    }
};
