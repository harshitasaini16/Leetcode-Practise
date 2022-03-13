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
        vector<int>ans;
        stack<TreeNode*>s;
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode *node=s.top()->right;
                if(node==NULL){
                    node=s.top();
                    s.pop();
                    ans.push_back(node->val);
                    while(!s.empty() && node==s.top()->right){
                        node=s.top();
                        s.pop();
                        ans.push_back(node->val);
                    }
                }
                else{
                    root=node;
                }
            }
        }
        return ans;
    }
};