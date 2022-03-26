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
    int cam=0;
    int fun(TreeNode *root){
        if(root==NULL){
            return 2;
        }
        int ls=fun(root->left);
        int rs=fun(root->right);
        if(ls==0 || rs==0){
            cam+=1;
            return 1;
        }
        if(ls==1 || rs==1){
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=fun(root);
        if(ans==0){
            return cam+1;
        }
        return cam;
    }
};