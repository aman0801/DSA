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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        ListNode* current = head;
        while (current->next != NULL){
            count++;
            current = current->next;
        }
        current = head;
        
        for(int i=0; i<k-1; i++){
            current = current->next;
        }
        
        for(int i=0; i<=count-k; i++){
            temp = temp->next;
        }
        int data;
        data = current->val;
        current->val = temp->val;
        temp->val = data;
        return head;
        
    }
};


        