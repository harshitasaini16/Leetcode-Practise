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
    vector<TreeNode*>ans;
    vector<TreeNode*> fun(int l,int r){
        if(l>r){
            return {NULL};
        }
        vector<TreeNode*>ans;
        for(int x=l;x<=r;x++){
            vector<TreeNode*>lt=fun(l,x-1);
            vector<TreeNode*>rt=fun(x+1,r);
            for(auto i:lt){
                for(auto j:rt){
                    TreeNode *node=new TreeNode(x);
                    node->left=i;
                    node->right=j;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);
    }
};