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
    bool check(TreeNode *a,TreeNode *b){
        if(a==NULL && b==NULL){
            return true;
        }
        if(a==NULL || b==NULL){
            return false;
        }
        if(a->val!=b->val){
            return false;
        }
        return (check(a->left,b->left) && check(a->right,b->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
        if(check(root,subRoot)){
            return true;
        }
        return (isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot));
    }
};