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
    map<int,int>m;
    int x;
    TreeNode *fun(int l,int r,vector<int>& pre){
        if(l<=r){
            int mid=m[pre[x]];
            TreeNode *root=new TreeNode(pre[x++]);
            root->left=fun(l,mid-1,pre);
            root->right=fun(mid+1,r,pre);
            return root;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        x=0;
        return fun(0,pre.size()-1,pre);
    }
};