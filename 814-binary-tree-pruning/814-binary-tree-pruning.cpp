class Solution {
public:
    bool fun(TreeNode*root){
        if(root==NULL){
            return  false;
        }
        if(root->left==NULL and root->right==NULL){
            if(root->val==1){
                return true;
            }
            return false;
        }
        bool l=fun(root->left);
        bool r=fun(root->right);
        if(l==0){
            root->left=NULL;
        }
        if(r==0){
            root->right=NULL;
        }
        if(root->val==1 || l==true || r==true){
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(fun(root)){
            return root;
        }
        return NULL;
    }
};