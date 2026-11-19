class Solution {
public:
    

    void find(TreeNode* root, int& k, int& res) {
        if(res > 0 || root == NULL) return;

        find(root->left,k,res);
        k--;
        if(k == 0) res = root->val;

        find(root->right,k,res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        find(root,k,res);
        return res;
    }
};