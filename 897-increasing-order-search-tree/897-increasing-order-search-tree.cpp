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
    vector<int>v;
    void fun(TreeNode *root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        v.clear();
        fun(root);
        TreeNode *node=new TreeNode(v[0]);
        root=node;
        for(int i=1;i<v.size();i++){
            TreeNode *n=new TreeNode(v[i]);
            root->right=n;
            root=n;
        }
        return node;
    }
};