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
    
    ListNode* middle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        
        while(left!=NULL){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        while(right!=NULL){
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
        return ans->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)return head;
        
        ListNode* mid = middle(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(newHead);
        return merge(left, right);
    }
};    