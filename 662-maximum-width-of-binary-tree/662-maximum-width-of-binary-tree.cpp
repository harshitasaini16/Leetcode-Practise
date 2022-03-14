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
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int mn=INT_MAX;
            int mx=INT_MIN;
            int s=q.front().second;
            while(size--){
                auto x=q.front().first;
                int y=q.front().second;
                y=y-s;
                if(y<mn){
                    mn=y;
                }
                if(y>mx){
                    mx=y;
                }
                q.pop();
                if(x->left!=NULL){
                    q.push({x->left,(long long)y*2+1});
                }
                if(x->right!=NULL){
                    q.push({x->right,(long long)y*2+2});
                }
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};