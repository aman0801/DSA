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
//         ListNode* temp1=headA;
//         ListNode* temp2=headB;
//         int count=0;
//         int count1=0;
//         while(temp1!=NULL){
//             temp1=temp1->next;
//             count++;
//         }
//         while(temp2!=NULL){
//             temp2=temp2->next;
//             count1++;
//         }
        
//         int diff=abs(count-count1);
        
//         if(count>count1){
//             while(diff){
//                 headA=headA->next;
//                 diff--;
//             }
//         }else{
//             while(diff){
//                 headB=headB->next;
//                 diff--;
//             }
//         }
        
//         while(headA!=NULL and headB!=NULL){
//             if(headA==headB){
//                 return headA;
//             }else{
//                 headA=headA->next;
//                 headB=headB->next;
//             }
//         }
//         return NULL;
        unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
    }
};