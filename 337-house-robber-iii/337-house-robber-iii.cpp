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
    map<pair<TreeNode*,bool>,int>m;
    int fun(TreeNode *root,bool f){
        if(root==NULL){
            return 0;
        }
        if(m.find({root,f})!=m.end()){
            return m[{root,f}];
        }
        if(f==true){
            int s1=root->val+fun(root->left,false)+fun(root->right,false);
            int s2=fun(root->left,true)+fun(root->right,true);
            return m[{root,f}]=max(s1,s2);
        }
        int s1=fun(root->left,true);
        int s2=fun(root->right,true);
        return m[{root,f}]=s1+s2;
    }
    int rob(TreeNode* root) {
        m.clear();
        return fun(root,true);
    }
};