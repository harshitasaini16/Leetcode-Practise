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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mn=INT_MAX;
            int mx=INT_MIN;
            int s=q.front().second;
            while(size--){
                TreeNode *n=q.front().first;
                int x=q.front().second;
                x=x-s;
                mn=min(mn,x);
                mx=max(mx,x);
                q.pop();
                if(n->left!=NULL){
                    q.push({n->left,(long long)2*x+1});
                }
                if(n->right!=NULL){
                    q.push({n->right,(long long)2*x+2});
                }
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};