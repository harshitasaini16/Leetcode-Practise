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
    int deepestLeavesSum(TreeNode* root) {
        int s=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            s=0;
            while(x--){
                TreeNode *n=q.front();
                q.pop();
                s+=n->val;
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
        }
        return s;
    }
};