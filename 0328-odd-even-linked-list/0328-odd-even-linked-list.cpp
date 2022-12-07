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
    void ans(ListNode* head){
        if(head->next == NULL || head == NULL){
            return;
        }
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* odd_dup = head;
        ListNode* even_dup = head -> next;
        while(odd!=NULL && even != NULL){
            odd -> next = even -> next;
            if(odd->next != NULL){
                even -> next = odd->next->next;
            }
            odd = odd->next;
            even=even->next;
        }
        while(odd_dup->next != NULL){
            odd_dup = odd_dup->next;
        }
        odd_dup->next = even_dup;
        
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ans(head);
        return head;
//         ListNode* temp1 = head;
//         ListNode* temp2 = head->next;
//         ListNode* head1 = NULL;
//         ListNode* head2 = NULL;
//         ListNode* temp3 = NULL;
//         while(temp1!=NULL){
//             if(head1 == NULL){
//                 head1 = temp1;
//                 temp3 = head1;
//             }
//             if(temp1->next != NULL){
//                 temp1 = temp1->next->next;
//                 temp3->next = temp1;
//                 temp3 = temp3->next;
//             }
//             else{
//                 temp1 = temp1->next;
//             }
//         }
        
//         while(temp2!=NULL){
//             if(head2 == NULL){
//                 head2 = temp2;
//             }
//             if(temp2->next != NULL){
//                 temp2 = temp2->next->next;
//             }
//             else{
//                 temp2 = temp2->next;
//             }
//         }
//         ListNode* temp3 = head1;
//         while(temp3->next !=NULL){
//             temp3=temp3->next;
//         }
//         temp3->next = head2;
//         return head1;
    }
};