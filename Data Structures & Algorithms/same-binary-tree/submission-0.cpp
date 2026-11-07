class Solution {
public:
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
};
