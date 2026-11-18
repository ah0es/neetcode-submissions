class Solution {
public:
    int c = 0;

    int find(TreeNode* root, int k) {
        if(root == NULL) return -1;

        int l = find(root->left, k);
        if(l != -1) return l;

        c++;

        if(c == k) return root->val;

        return find(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};