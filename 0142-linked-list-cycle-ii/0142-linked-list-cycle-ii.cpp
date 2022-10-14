/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* dcy(ListNode *sp, ListNode *lp){
        while(sp != lp){
            if(sp == NULL || lp == NULL || lp->next == NULL){
                return NULL;
            }
            sp = sp -> next;
            lp = lp -> next -> next;
        }
        return sp;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head;
        
        if(temp == NULL || temp->next == NULL || temp->next->next==NULL){
            return NULL;
        }
        
        
        ListNode *res = dcy(temp->next,temp->next->next);
        if (res == NULL)
            return res;
        
        temp = head;
        while(temp != res){
            temp = temp -> next;
            res = res -> next;
        }
        return res;
    }
};