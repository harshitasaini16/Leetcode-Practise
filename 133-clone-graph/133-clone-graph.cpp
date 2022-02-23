/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(clones.find(node)==clones.end()){
            clones[node]=new Node(node->val,{});
            for(Node* i:node->neighbors){
                clones[node]->neighbors.push_back(cloneGraph(i));
            }
        }
        return clones[node];
    }
private:
    map<Node*,Node*>clones;
};