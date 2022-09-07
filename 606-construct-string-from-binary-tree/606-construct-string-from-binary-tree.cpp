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
    void fun(TreeNode *root,string &s){
        if(root==NULL){
            return;
        }
        s=s+to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->left!=NULL){
            s=s+'(';
            fun(root->left,s);
            s=s+')';
        }
        else{
            s=s+"()";
        }
        if(root->right!=NULL){
            s=s+'(';
            fun(root->right,s);
            s=s+')';
        }
        
    }
    string tree2str(TreeNode* t) {
        string s="";
        fun(t,s);
        return s;
    }
};