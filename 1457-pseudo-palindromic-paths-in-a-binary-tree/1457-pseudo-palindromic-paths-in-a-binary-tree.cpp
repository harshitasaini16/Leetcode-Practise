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
    void fun(TreeNode* root,vector<int>v){
        if(root==NULL){
           return;
        }
        v[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int x=0;
            for(int i=1;i<=9;i++){
                if(v[i]%2!=0){
                    x++;
                }
            }
            if(x<=1){
                ans++;
            }
        }
        if(root->left!=NULL){
            fun(root->left,v);
        }
        if(root->right!=NULL){
            fun(root->right,v);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        vector<int>v(10,0);
        fun(root,v);
        return ans;
    }
};