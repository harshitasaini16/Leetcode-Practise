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
    TreeNode *fun(int &x,int l,int r, vector<int>& postorder){
        if(l<=r){
            TreeNode *n=new TreeNode(postorder[x]);
            int y=m[postorder[x--]];
            n->right=fun(x,y+1,r,postorder);
            n->left=fun(x,l,y-1,postorder);
            return n;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m.clear();
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int in=postorder.size()-1;
        return fun(in,0,inorder.size()-1,postorder);
    }
};