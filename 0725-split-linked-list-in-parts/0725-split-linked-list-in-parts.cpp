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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        if(head == NULL){
            return ans;
        }
        int temp = k;
        int temp1;
        ListNode* tempnode = head;
        int count = 1;
        unordered_map<int, ListNode*> map;
        while(tempnode != NULL){
            map[count] = tempnode;
            count++;
            tempnode = tempnode -> next;
        }
        count--;
        tempnode = head;
        int ind = 0;
        int s = 1;
        while(k){
            temp1 = ceil((double)count / (double)k);
            if(temp1 == 0){
                while(count){
                    map[ind+1]->next = NULL;
                    ans[ind] = map[ind+1];
                    ind++;
                    count--;
               }
               return ans;
            }
            
            map[temp1 + s - 1]->next = NULL;
            ans[ind] = map[s];
            ind++;
            s = temp1+s;
            k--;
            count = count - temp1;
        }
        return ans;
    }
};