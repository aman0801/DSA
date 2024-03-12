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
    ListNode* removeZeroSumSublists(ListNode* head) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            unordered_map<int, ListNode*>mp;
            mp[0] = dummy;
            int sum = 0;
            
            while(head!=NULL){
                    sum = sum + head->val;
                    if(mp.find(sum)!=mp.end()){
                            ListNode* st = mp[sum];
                            ListNode* tmp = st;
                            int psum = sum;
                            while(tmp!=head){
                                    tmp = tmp->next;
                                    psum = psum + tmp->val;
                                    if(tmp!=head){
                                            mp.erase(psum);
                                    }
                                    st->next = tmp->next;
                            }
                    }else{
                            mp[sum] = head;
                    }
                    head = head->next;
            }
            return dummy->next;
    }
};