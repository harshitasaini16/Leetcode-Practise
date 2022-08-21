/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root,int &l,int &r){
        if(root==NULL){
            return 0;
        }
        int ll=0,lr=0,rl=0,rr=0;
        l=fun(root->left,ll,lr);
        r=fun(root->right,rl,rr);
        return max({root->val+lr+rr+rl+ll,l+r});
    }
    int rob(TreeNode* root) {
        int l=0;
        int r=0;
        return fun(root,l,r);
    }
};