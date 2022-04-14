class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
           if(root==NULL)
               return NULL;
        TreeNode *node =NULL;
        if(val<root->val)
            node = searchBST(root->left,val);
        else if(val>root->val)
            node = searchBST(root->right,val);
        else if(val==root->val)
              node = root;
        return node;
    }
};