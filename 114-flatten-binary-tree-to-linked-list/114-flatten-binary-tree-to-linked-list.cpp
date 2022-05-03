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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            flatten(root->left);
            TreeNode *n=root->left;
            TreeNode *f=root->right;
            TreeNode *g=n;
            while(g->right!=NULL){
                g=g->right;
            }
            root->right=n;
            g->right=f;
            root->left=NULL;
        }
        flatten(root->right);
    }
};