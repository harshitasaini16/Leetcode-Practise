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
            TreeNode *l=root->left;
            TreeNode *r=root->right;
            root->left=NULL;
            root->right=l;
            TreeNode *q=l;
            while(q->right!=NULL){
                q=q->right;
            }
            q->right=r;
        }
        if(root->right!=NULL){
            flatten(root->right);
        }
    }
};