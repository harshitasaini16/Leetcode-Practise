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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        int x=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                TreeNode* n=q.front();
                v.push_back(n->val);
                q.pop();
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
            if(x%2==0){
                ans.push_back(v);
            }
            else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            x++;
        }
        return ans;
    }
};