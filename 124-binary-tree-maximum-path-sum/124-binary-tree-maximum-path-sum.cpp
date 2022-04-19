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
    int ans=INT_MIN;
    int fun(TreeNode *root){
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,root->val);
            return root->val;
        }
        if(root->left==NULL){
            int r=fun(root->right);
            ans=max({ans,r,root->val,r+root->val});
            return max({root->val+r,root->val});
        }
        if(root->right==NULL){
            int l=fun(root->left);
            ans=max({ans,l,root->val,l+root->val});
            return max({root->val+l,root->val});
        }
        int l=fun(root->left);
        int r=fun(root->right);
        ans=max({ans,l+r+root->val,root->val,l+root->val,r+root->val});
        return max({root->val+l,root->val+r,root->val});
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        fun(root);
        return ans;
    }
};