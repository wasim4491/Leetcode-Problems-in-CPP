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
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode *small = head, *fast = head->next;
        while(small != NULL && fast != NULL && fast->next != NULL){
            if(small == fast){
                return true;
            }
            small = small -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};