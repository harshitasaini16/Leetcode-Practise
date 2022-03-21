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
class FindElements {
public:
    map<int,int>m;
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode *x=q.front().first;
            int y=q.front().second;
            q.pop();
            m[y]++;
            if(x->left!=NULL){
                q.push({x->left,2*y+1});
            }
            if(x->right!=NULL){
                q.push({x->right,2*y+2});
            }
        }
    }
    
    bool find(int x) {
        if(m[x]==0){
            return false;
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */