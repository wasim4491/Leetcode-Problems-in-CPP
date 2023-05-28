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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
       Node* newnode = new Node(node->val);
        vector<Node*> nodenbrs;
        mp[node] = newnode;
        for(auto it : node->neighbors){
            if(mp.find(it) != mp.end()){
                nodenbrs.push_back(mp[it]);
            }
            else{
                nodenbrs.push_back(dfs(it,mp));
            }
        }
        newnode->neighbors = nodenbrs;
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(node->neighbors.size() == 0){
            Node *newnode = new Node(node->val);
            return newnode;
        }
       // Node* newnode = new Node(node->val);
        int n = node->neighbors.size();
       // vector<bool> visited(n+1, false);
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};