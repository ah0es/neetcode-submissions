class Solution {
public:

    vector<int> list;
    void getList(TreeNode* root){
        if(root == NULL) return;
        getList(root->left);
        list.push_back(root->val);
        getList(root->right);
    }

    bool isValidBST(TreeNode* root) {
        
        getList(root);
        for(int i = 1; i < list.size(); i++){
            if(list[i] <= list[i - 1]) return false;
        }

        return true;
    }
};