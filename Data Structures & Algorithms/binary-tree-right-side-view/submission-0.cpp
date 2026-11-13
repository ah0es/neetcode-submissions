class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            TreeNode* top = q.front();
            ans.push_back(top->val);

            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                q.pop();
                if (top->right != NULL) {
                    q.push(top->right);
                }
                if (top->left != NULL) {
                    q.push(top->left);
                }
            }
        }

        return ans;
    }
};