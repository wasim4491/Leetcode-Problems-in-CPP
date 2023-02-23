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
    Node* dfs(Node* node, unordered_map<Node*,Node*> &mp){
        vector<Node*> nbrs;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        for(auto i : node->neighbors){
            if(mp.find(i) != mp.end()){
                nbrs.push_back(mp[i]);
            }
            else{
                nbrs.push_back(dfs(i,mp));
            }
        }
        clone->neighbors = nbrs;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(node -> neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node*, Node*> mp;
        return dfs(node,mp);
    }
};