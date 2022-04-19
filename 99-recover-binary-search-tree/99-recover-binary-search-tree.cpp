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
    void fun(TreeNode *n){
        if(n==NULL){
            return;
        }
        fun(n->left);
        v.push_back(n->val);
        fun(n->right);
    }
    int x=0;
    void f(TreeNode *n){
        if(n==NULL){
            return;
        }
        f(n->left);
        n->val=v[x];
        x++;
        f(n->right);
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        sort(v.begin(),v.end());
        f(root);
    }
};