/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                Node *n=q.front();
                q.pop();
                v.push_back(n->val);
                for(int i=0;i<n->children.size();i++){
                    q.push(n->children[i]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};