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
private: 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q == NULL && p != NULL || q != NULL && p == NULL) return false;
        if(q == NULL && p == NULL) return true;
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        if(p->val != q->val){
            return false;
        }
        return l && r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val && isSameTree(root,subRoot)){
            return true;
        }
        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);
        return l || r;
        
    }
};
