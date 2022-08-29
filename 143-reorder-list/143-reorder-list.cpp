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
    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        int right=arr.size()-1;
        int left=0;
        temp=head;
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                temp->val=arr[left];
                left++;
                temp=temp->next;
            }else{
                temp->val=arr[right];
                right--;
                temp=temp->next;
            }
        }
        // return temp->next;
    }
};