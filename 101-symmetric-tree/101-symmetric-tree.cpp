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
    bool fun(TreeNode* h1,TreeNode *h2){
        if(h1==NULL && h2==NULL){
            return true;
        }
        if(h1==NULL || h2==NULL){
            return false;
        }
        if(h1->val!=h2->val){
            return false;
        }
        return (fun(h1->left,h2->right) && fun(h1->right,h2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return fun(root->left,root->right);
    }
};