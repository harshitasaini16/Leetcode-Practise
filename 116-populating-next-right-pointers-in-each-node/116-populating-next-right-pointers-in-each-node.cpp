/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            // bool f=false;
            Node *n=new Node(-1);
            while(x--){
                Node* d=q.front();
                n->next=d;
                n=d;
                q.pop();
                if(d->left!=NULL){
                    q.push(d->left);
                }
                if(d->right!=NULL){
                    q.push(d->right);
                }
            }
        }
        return root;
    }
};