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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* st = list1;
            ListNode* end = list1;
            
            while(a-1!=0){
                    st = st->next;
                    a--;
            }
            while(b+1!=0){
                    end = end->next;
                    b--;
            }
            ListNode* listhead = list2;
            ListNode* listtail = list2;

            while(listtail->next!=NULL){
                    listtail = listtail->next;
            }
            st->next = listhead;
            listtail->next = end;
            return list1;
    }
};