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
    TreeNode *fun(int l,int r,vector<int>& pre,int &x){
        if(l<=r){
            TreeNode *root=new TreeNode(pre[x++]);
            int mid=m[root->val];
            root->left=fun(l,mid-1,pre,x);
            root->right=fun(mid+1,r,pre,x);
            return root;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        m.clear();
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        int x=0;
        return fun(0,in.size()-1,pre,x);
    }
};