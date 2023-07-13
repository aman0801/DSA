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
        int height(ListNode*head){
                int count = 0;
                while(head!=NULL){
                        head = head->next;
                        count++;
                }
                return count;
        }
        
        ListNode* rev(ListNode* head, int k, int len){
                if(len<k){
                        return head;
                }
                
                ListNode* prev = NULL;
                ListNode* curr = head;
                ListNode* next = NULL;
                int count = 0;
                
                while(curr!=NULL && count<k){
                        next = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = next;
                        count++;
                }
                if(next!=NULL){
                      head->next = rev(next, k, len-k);
                }
                return prev;
        }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = height(head);
            return rev(head, k, len);
    }
};