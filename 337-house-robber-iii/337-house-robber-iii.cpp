class Solution {
public:
    int fun(TreeNode* root,int &l,int &r){
        if(root==NULL){
            return 0;
        }
        int ll=0,lr=0,rl=0,rr=0;
        l=fun(root->left,ll,lr);
        r=fun(root->right,rl,rr);
        return max({root->val+ll+lr+rl+rr,l+r});
    }
    int rob(TreeNode* root) {
        int x=0;
        int y=0;
        return fun(root,x,y);
    }
};