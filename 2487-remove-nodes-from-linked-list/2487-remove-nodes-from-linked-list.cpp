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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* dummy1=dummy;
        ListNode* get_rev=reverse(head);
        ListNode* curr=get_rev;
        int maxi=0;
        while(curr!=NULL){
            maxi=max(maxi,curr->val);
           
            if(maxi==curr->val){
                ListNode* temp=new ListNode(maxi);
                dummy->next=temp;
                dummy=dummy->next;
            }
            curr=curr->next;
        }
    
        return reverse(dummy1->next);
    }
};