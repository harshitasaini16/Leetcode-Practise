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
            int mn,mx;
            int x=q.front().second;
            for(int i=0;i<size;i++){
                int id=q.front().second-x;
                TreeNode*tt=q.front().first;
                q.pop();
                if(i==0){
                    mn=id;
                }
                if(i==size-1){
                    mx=id;
                }
                if(tt->left){
                    q.push({tt->left,(long long)2*id +1});
                }
                if(tt->right){
                    q.push({tt->right,(long long)2*id +2});
                }
            }
            ans=max(ans,1+(mx-mn));
        }
        return ans;
    }
};