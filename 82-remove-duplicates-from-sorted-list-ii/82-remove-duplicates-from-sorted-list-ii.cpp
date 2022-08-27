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
    ListNode* deleteDuplicates(ListNode* head) {
        // unordered_map<int,int>mp;
        map<int,int>mp;
         ListNode* dummy=new ListNode(0);
         // dummyNode->next=head; 
         ListNode* curr=dummy;
                 ListNode* c=dummy;

        
        while(head!=NULL){
            mp[head->val]++;
            head=head->next;
        }
        
        for(auto &i:mp){
            if(i.second==1){
                //Node
            ListNode* x= new ListNode(i.first);
               curr->next=x; 
                curr=curr->next;
            }
        }
        return c->next;
    }
};