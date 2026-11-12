class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(root);
        int qVal = q->val , pVal = p->val ;
        
        while (!qu.empty()) {
            TreeNode* top = qu.front();
            int rVal = top->val;
            qu.pop();
            if ((pVal < rVal && qVal > rVal) || (pVal > rVal && qVal < rVal)) {
                qu = queue<TreeNode*>();
                return top;
            }
            else if (p == top) {
                qu = queue<TreeNode*>();
                return p;
            }else if(q == top){
                qu = queue<TreeNode*>();
                return q;
            }
            if (qVal < rVal && pVal < rVal && top->left != NULL) {
                qu.push(top->left);
            }
            else if(top->right != NULL) {
                qu.push(top->right);
            }
        }
        return NULL;
    }
};