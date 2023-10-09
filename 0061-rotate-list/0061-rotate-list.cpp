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
    
    int Count(ListNode* head){
        int count = 0;
        
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return 0;
        int count = Count(head);
        int num = k%count;
        if(num == 0)return head;
        num = count-num-1;
        ListNode* newHead = NULL;
        ListNode* last = head;
        for(int i=0; i<num; i++){
            last = last->next;
        }
        newHead = last->next;
        last->next = NULL;
        ListNode*temp = newHead;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        return newHead;
    }
};