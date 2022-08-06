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
    TreeNode* fun(int l,int r,vector<int>& preorder){
        if(l<=r){
            TreeNode *n=new TreeNode(preorder[x]);
            int d=m[preorder[x]];
            x++;
            n->left=fun(l,d-1,preorder);
            n->right=fun(d+1,r,preorder);
            return n;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m.clear();
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        x=0;
        return fun(0,preorder.size()-1,preorder);
    }
};