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
    bool fun(TreeNode *root,int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(targetSum-root->val==0){
                return true;
            }
            return false;
        }
        return (fun(root->left,targetSum-root->val) || fun(root->right,targetSum-root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root,targetSum);
    }
};