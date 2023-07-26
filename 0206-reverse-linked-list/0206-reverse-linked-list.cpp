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
    ListNode* reverseList(ListNode* head) {
        unordered_map<int, ListNode*> map;
        ListNode* temp = head;
        int ind = 0;
        while(temp != NULL){
            map[ind++] = temp;
            temp = temp -> next;
        }
        ind--;
        
        ListNode* newhead = NULL;
        ListNode* last = NULL;
        while(ind >= 0){
            ListNode* temp = new ListNode(map[ind]->val);
            if(newhead == NULL){
                newhead = temp;
                last = newhead;
            }
            else{
                last->next = temp;
                last = temp;
            }
            ind--;
        }
        
        return newhead;
    }
};