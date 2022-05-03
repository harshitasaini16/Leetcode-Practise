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
            Node *f=new Node(-1);
            while(x--){
                Node *n=q.front();
                q.pop();
                f->next=n;
                f=f->next;
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
        }
        return root;
    }
};