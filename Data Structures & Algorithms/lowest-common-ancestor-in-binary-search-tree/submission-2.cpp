class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(root);

        int pv = p->val, qv = q->val;

        while (!qu.empty()) {
            TreeNode* cur = qu.front();
            qu.pop();

            int rv = cur->val;

            if ((pv < rv && qv > rv) || (pv > rv && qv < rv))
                return cur;

            if (cur == p || cur == q)
                return cur;

            if (pv < rv && qv < rv && cur->left)
                qu.push(cur->left);
            else if (cur->right)
                qu.push(cur->right);
        }

        return nullptr;
    }
};