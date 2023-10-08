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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int countA = 0;
        int countB = 0;
        while(tempA!=NULL){
            countA++;
            tempA = tempA->next;
        }
        tempA = headA;
        while(tempB!=NULL){
            countB++;
            tempB = tempB->next;
        }
        tempB = headB;
        
        int count = abs(countA-countB);
        
        if(countA > countB){
            while(count--){
                tempA = tempA->next;
            }
        } else {
            while(count--){
                tempB = tempB->next;
            }
        }
        
        while(tempA!=NULL && tempB!=NULL){
            if(tempA == tempB){
                return tempA;
            }
                tempA = tempA->next;
                tempB = tempB->next;
            
        }
        return NULL;
    }
};