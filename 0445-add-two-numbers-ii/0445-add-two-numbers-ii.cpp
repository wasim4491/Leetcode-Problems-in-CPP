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
void append(ListNode* &head_ref, int new_data)
{
	ListNode* new_node = new ListNode(new_data);
	ListNode* last = head_ref;
	if (head_ref == NULL) {
		head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        while(temp1 != NULL){
            st1.push(temp1->val);
            temp1 = temp1 -> next;
        }
        
        while(temp2 != NULL){
            st2.push(temp2->val);
            temp2 = temp2 -> next;
        }
        
        stack<int> st;
        int a,b, c=0,s=0;
        while(!st1.empty() && !st2.empty()){
            a = st1.top();
            b = st2.top();
            s = (a + b + c) % 10;
            c = (a + b + c) / 10;
            st.push(s);
            st1.pop();
            st2.pop();
        }
        while(!st1.empty()){
            s = (c + st1.top()) % 10;
            c = (c + st1.top()) / 10;
            st.push(s);
            st1.pop();
        }
        while(!st2.empty()){
             s = (c + st2.top()) % 10;
            c = (c + st2.top()) / 10;
            st.push(s);
            st2.pop();
        }
        if(c != 0){
            st.push(c);
        }
        ListNode* head = NULL;
        while(!st.empty()){
            append(head, st.top());
            st.pop();
        }
        
        return head;
        
    }
};