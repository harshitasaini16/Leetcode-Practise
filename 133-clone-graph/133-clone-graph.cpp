
class Solution {
public:
    map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(m.find(node)==m.end()){
            m[node]=new Node(node->val,{});
            for(Node* i:node->neighbors){
                m[node]->neighbors.push_back(cloneGraph(i));
            }
        }
        return m[node];
    }
};