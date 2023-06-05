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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* s = ans;
        ListNode* temp = head;
        int sum = 0;
        temp = temp->next;
        while(temp!=NULL){
            if(temp->val==0){
                ans->next = new ListNode(sum);
                ans = ans->next;
                sum = 0;
            }else{
                sum = sum+temp->val;
            }
            temp = temp->next;
        }
        return s->next;
    }
};