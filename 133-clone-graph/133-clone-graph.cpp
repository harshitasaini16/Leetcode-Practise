class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* i : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(i));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};