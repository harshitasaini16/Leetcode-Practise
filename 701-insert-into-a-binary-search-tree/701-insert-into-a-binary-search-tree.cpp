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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *n=new TreeNode(val);
        if(root==NULL){
            return n;
        }
        if(val<root->val && root->left==NULL){
            root->left=n;
            return root;
        }
        else if(val<root->val && root->left!=NULL){
            root->left=insertIntoBST(root->left,val);
            return root;
        }
        if(val>root->val && root->right==NULL){
            root->right=n;
            return root;
        }
        else if(val>root->val && root->right!=NULL){
            root->right=insertIntoBST(root->right,val);
            return root;
        }
        return root;
    }
};