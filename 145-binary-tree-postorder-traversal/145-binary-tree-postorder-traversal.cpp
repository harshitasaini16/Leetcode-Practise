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
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode *n=s.top()->right;
                if(n==NULL){
                    n=s.top();
                    ans.push_back(n->val);
                    s.pop();
                    while(!s.empty() && n==s.top()->right){
                        n=s.top();
                        s.pop();
                        ans.push_back(n->val);
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