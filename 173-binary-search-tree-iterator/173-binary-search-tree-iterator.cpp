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
class BSTIterator {
public:
    vector<int>v;
    int x;
    void fun(TreeNode *root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    BSTIterator(TreeNode* root) {
        v.clear();
        fun(root);
        x=0;
    }
    
    int next() {
        if(x>=v.size()){
            return -1;
        }
        return v[x++];
    }
    
    bool hasNext() {
        if(x>=v.size()){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */