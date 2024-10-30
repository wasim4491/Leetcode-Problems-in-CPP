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
    void helper(ListNode* cur, ListNode* prev, ListNode* &head){
        if(cur == NULL){
            head = prev;
            return;
        }
        helper(cur->next, cur, head);
        cur->next = prev;
        prev->next = NULL;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* cur = head->next;
        ListNode* prev = head;
        
        helper(cur, prev, head);
        return head;
    }
};