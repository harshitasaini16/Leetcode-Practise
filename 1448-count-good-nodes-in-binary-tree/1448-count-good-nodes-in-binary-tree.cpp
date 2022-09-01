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
    int fun(TreeNode *root,int mx){
        if(root==NULL){
            return 0;
        }
        int ans=1;
        if(root->val<mx){
            ans=0;
        }
        mx=max(mx,root->val);
        return ans+fun(root->left,mx)+fun(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return fun(root,root->val);
    }
};