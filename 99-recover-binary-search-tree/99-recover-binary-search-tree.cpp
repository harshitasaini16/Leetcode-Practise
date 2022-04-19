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
    TreeNode *a,*b;
    TreeNode *c=new TreeNode(INT_MIN);
    void fun(TreeNode *root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        if(a==NULL && c->val>root->val){
            a=c;
        }
        if(a!=NULL && c->val>root->val){
            b=root;
        }
        c=root;
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL){
            return;
        }
        fun(root);
        swap(a->val,b->val);
    }
};