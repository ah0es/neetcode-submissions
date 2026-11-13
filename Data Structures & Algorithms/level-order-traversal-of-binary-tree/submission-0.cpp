class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if (root != nullptr) {
            q.push(root);
        }

        vector<vector<int>> ans;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                level.push_back(top->val);

                if (top->left != nullptr) {
                    q.push(top->left);
                }

                if (top->right != nullptr) {
                    q.push(top->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};