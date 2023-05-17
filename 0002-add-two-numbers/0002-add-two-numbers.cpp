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
    
    ListNode* solve(ListNode* l1, ListNode* l2, int carry){
        if(l1 == NULL && l2 == NULL && carry == 0){
            return NULL;
        }
        
        int sum = carry;
        if(l1!=NULL){
            sum = sum + l1->val;
        }else{
            sum = sum + 0;
        }
        
        if(l2!=NULL){
            sum = sum + l2->val;
        }else{
            sum = sum + 0;
        }
        
        ListNode*newNode=new ListNode(sum%10);
        carry=sum/10;
        
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
        newNode->next=solve(l1,l2,carry);
        return newNode;
        
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};


