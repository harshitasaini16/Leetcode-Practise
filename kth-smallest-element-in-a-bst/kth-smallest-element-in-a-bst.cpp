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
    int x;
    int ans;
    void fun(TreeNode *root,int k){
        if(root==NULL){
            return;
        }
        fun(root->left,k);
        x++;
        if(x==k){
            ans=root->val;
            return;
        }
        fun(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        x=0;
        ans=0;
        fun(root,k);
        return ans;
    }
};