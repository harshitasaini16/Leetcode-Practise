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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty()){
                    return ans;
                }
                TreeNode *x=s.top();
                ans.push_back(x->val);
                s.pop();
                root=x->right;
            }
        }
        return ans;
    }
};