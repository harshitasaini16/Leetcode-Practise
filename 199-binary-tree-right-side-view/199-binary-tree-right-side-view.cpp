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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            int p=-1;
            while(x--){
                TreeNode *n=q.front();
                p=n->val;
                q.pop();
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
            v.push_back(p);
        }
        return v;
    }
};