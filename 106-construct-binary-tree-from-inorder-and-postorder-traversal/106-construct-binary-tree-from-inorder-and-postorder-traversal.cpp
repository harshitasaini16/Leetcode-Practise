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
    TreeNode* fun(int l,int r,vector<int>& postorder){
        if(l<=r){
            TreeNode *n=new TreeNode(postorder[x]);
            int y=m[postorder[x--]];
            n->right=fun(y+1,r,postorder);
            n->left=fun(l,y-1,postorder);
            return n;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        x=postorder.size()-1;
        m.clear();
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return fun(0,postorder.size()-1,postorder);
    }
};