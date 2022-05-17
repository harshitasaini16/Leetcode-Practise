/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans;
    void fun(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL){
            return;
        }
        if(original==target){
            ans=cloned;
            return;
        }
        fun(original->left,cloned->left,target);
        fun(original->right,cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ans=NULL;
        fun(original,cloned,target);
        return ans;
    }
};