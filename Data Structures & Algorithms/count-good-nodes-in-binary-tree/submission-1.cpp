class Solution {
public:
    
    int count = 0;
    void recursiveFun(TreeNode* root, int largestValue){
        if(root == NULL) return;
        if(root->val >= largestValue){
         largestValue = root->val;
         count++;
       }
       recursiveFun(root->left,largestValue);
       recursiveFun(root->right,largestValue);
       
    }
    int goodNodes(TreeNode* root) {
        int largestValue =INT_MIN;
       recursiveFun(root,largestValue);
       return count;
    }
};
