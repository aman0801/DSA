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
    int pairSum(ListNode* head) {
       vector<int>arr;
        int sum = INT_MIN;
        ListNode* current = head;
        
        while(current!=nullptr){
            arr.push_back(current->val);
            current = current->next;
        }
        int temp = 0;
        for(int i=0; i<=(arr.size()/2)-1; i++){
            temp = arr[i] + arr[arr.size()-1-i];
            if(temp > sum){
                sum = temp;
            }
            
        }
        return sum;
    }
};