/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* pivot;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val >= x){
                break;
            }
            temp = temp -> next;
        }
        
        vector<ListNode*> temparr;
        
        ListNode* cur = temp;
        ListNode* prev = temp;
        while(cur != NULL){
            if(cur->val < x){
                temparr.push_back(cur);
                prev->next = cur->next;
                cur->next = NULL;
                cur = prev->next;
            }
            else{
                prev = cur;
                cur = cur -> next;
            }
        }
        ListNode *newtemp = head;
        while(temp != head && newtemp->next != temp){
            newtemp = newtemp -> next;
        }
        for(int i=0; i<temparr.size(); i++){
            if(newtemp == head && temp == head){
                temparr[i] -> next = head;
                head = temparr[i];
                newtemp = head;
            }
            newtemp -> next = temparr[i];
            temparr[i] -> next = temp;
            newtemp = temparr[i];
        }
        
        return head;
        
    }
};