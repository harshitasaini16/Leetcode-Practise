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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        stack<TreeNode*>s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode *n=s.top()->right;
                if(n==NULL){
                    TreeNode *x=s.top();
                    s.pop();
                    ans.push_back(x->val);
                    while(!s.empty() && s.top()->right==x){
                        x=s.top();
                        ans.push_back(x->val);
                        s.pop();
                    }
                }
                else{
                    root=n;
                }
            }
        }
        return ans;
    }
};