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
    int mx;
    vector<int>v;
    map<int,int>m;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        int x=root->val+l+r;
        m[x]++;
        if(m[x]>mx){
            v.clear();
            v.push_back(x);
            mx=m[x];
        }
        else if(m[x]==mx){
            v.push_back(x);
        }
        return x;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mx=1;
        v.clear();
        m.clear();
        fun(root);
        return v;
    }
};