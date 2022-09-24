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
    vector<vector<int>>ans;
    void fun(TreeNode *root,int target,vector<int>v){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            target-=root->val;
            v.push_back(root->val);
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        if(root->left==NULL){
            fun(root->right,target-root->val,v);
            return;
        }
        if(root->right==NULL){
            fun(root->left,target-root->val,v);
            return;
        }
        fun(root->left,target-root->val,v);
        fun(root->right,target-root->val,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int>v;
        fun(root,targetSum,v);
        return ans;
    }
};