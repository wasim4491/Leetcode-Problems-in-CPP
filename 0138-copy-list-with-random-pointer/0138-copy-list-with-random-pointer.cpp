/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* newhead = NULL;
        unordered_map<Node*, Node*> map;
        Node* temp = head;
        Node* newtemp = NULL;
        while(temp != NULL){
            Node* newnode = new Node(temp->val);
            map[temp] = newnode;
            if(newhead == NULL){
                newhead = newnode;
                newtemp = newhead;
            }
            else{
                newtemp->next = newnode;
                newtemp = newnode;
            }
            temp = temp -> next;
        }
        
        Node* temp1 = head;
        Node* temp2 = newhead;
        
        while(temp1 != NULL){
            temp2->random = map[temp1->random];
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        return newhead;
    }
};