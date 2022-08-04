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
           
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        ListNode* list3=new ListNode(0);
        ListNode* curr=list3;
        
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        while(list1 and list2){
            if(list1->val<=list2->val){
                list3->next=list1;
                list1=list1->next;
                list3=list3->next;

            }else{
                list3->next=list2;
                list2=list2->next;
                list3=list3->next;

            }

        }
        while(list1!=NULL){
                list3->next=list1;
                list1=list1->next;
                list3=list3->next;
        }
        while(list2!=NULL){
                list3->next=list2;
                list2=list2->next;
                list3=list3->next;
        }
        return curr->next;
    }
};