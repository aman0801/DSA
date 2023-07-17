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
        ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp;
        while (head) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode*ans = new ListNode();
          ListNode* L1 = reverseList(l1);
          ListNode* L2 = reverseList(l2);
          int sum = 0;
          int carry = 0;
          while(L1!=NULL || L2!=NULL){
               if(L1!=NULL){
                       sum = sum+L1->val;
                       L1 = L1->next;
               }
               if(L2!=NULL){
                       sum = sum+L2->val;
                       L2 = L2->next;
               }
                  
                  ans->val = sum%10;
                  carry = sum/10;
                  ListNode* head = new ListNode(carry);
                  head->next = ans;
                  ans = head;
                  sum = carry;
          }
            
            if(carry == 0){
                    return ans->next;
            }
            return ans;
            
    }
};