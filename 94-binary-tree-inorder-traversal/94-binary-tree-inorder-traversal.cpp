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
        vector<int>ans;
        stack<TreeNode*>s;
        while(true){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            if(s.empty()){
                return ans;
            }
            else{
                TreeNode* x=s.top();
                s.pop();
                ans.push_back(x->val);
                root=x->right;
            }
        }
        return ans;
    }
};