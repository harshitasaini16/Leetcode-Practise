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
    int ans;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        ans=max({ans,l+r+root->val,root->val,root->val+l,root->val+r});
        return max({root->val,root->val+l,root->val+r});
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        fun(root);
        return ans;
    }
};