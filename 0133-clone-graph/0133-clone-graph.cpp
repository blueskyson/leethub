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
        if (node == nullptr)
            return nullptr;
        queue<pair<Node*, Node*>> q;
        unordered_map<Node*, Node*> map;
        Node *head = new Node(node->val);
        q.push(pair<Node*, Node*>(node, head));
        map[node] = head;
        while (!q.empty()) {
            pair<Node*, Node*> p = q.front();
            q.pop();
            Node *n1 = p.first, *n2 = p.second;
            for (int i = 0; i < n1->neighbors.size(); i++) {
                Node *neighbor = n1->neighbors[i];
                if (map.find(neighbor) != map.end()) {
                    n2->neighbors.push_back(map[neighbor]);
                } else {
                    Node *new_node = new Node(neighbor->val);
                    n2->neighbors.push_back(new_node);
                    map[neighbor] = new_node;
                    q.push(pair<Node*, Node*>(neighbor, new_node));
                }
            }
        }
        return head;
    }
};