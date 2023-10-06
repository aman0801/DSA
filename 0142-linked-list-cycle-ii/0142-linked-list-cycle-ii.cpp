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
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ans = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(ans!=slow){
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
        }
        return NULL;
    }
};