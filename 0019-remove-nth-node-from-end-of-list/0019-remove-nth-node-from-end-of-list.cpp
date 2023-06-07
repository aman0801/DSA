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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* curr = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        if((count-n)==0)
            return head->next;
        for(int i=1; i<(count-n); i++){
            temp = temp -> next;
        }
        
        temp->next=temp->next->next;
        
        return head;
        
    }
};