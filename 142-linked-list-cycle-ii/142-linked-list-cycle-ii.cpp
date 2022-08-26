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
    ListNode *detectCycle(ListNode *head) {
       if (head == NULL || head->next == NULL)
        return NULL;
        
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *ans=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow != ans) {               
                slow  = slow->next;
                ans = ans->next;
            }
                return ans;
            }
        }
        return NULL;
    }
};