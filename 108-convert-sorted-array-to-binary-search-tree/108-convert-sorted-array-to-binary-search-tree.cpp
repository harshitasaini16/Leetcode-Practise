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
    TreeNode *fun(int l,int r,vector<int>& nums){
        if(l<=r){
            int mid=l+(r-l)/2;
            TreeNode *root=new TreeNode(nums[mid]);
            root->left=fun(l,mid-1,nums);
            root->right=fun(mid+1,r,nums);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(0,nums.size()-1,nums);
    }
};