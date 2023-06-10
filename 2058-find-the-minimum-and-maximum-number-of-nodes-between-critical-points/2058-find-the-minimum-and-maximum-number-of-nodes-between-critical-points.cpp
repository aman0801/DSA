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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev = head;
        ListNode* agla = head->next->next;

        vector<int> distances;

        int count = 1;
        while (agla != nullptr) {
            if ((temp->val > prev->val && temp->val > agla->val) ||
                (temp->val < prev->val && temp->val < agla->val)) {
                distances.push_back(count);
            }

            temp = temp->next;
            prev = prev->next;
            agla = agla->next;
            count++;
        }

        if(distances.size()==0||distances.size()==1)
            return {-1,-1};
        

        vector<int> ans;
        
        int minn=INT_MAX,maxx=distances[distances.size()-1]-distances[0];
        
        for(int i=1;i<distances.size();i++){
            minn=min(minn,distances[i]-distances[i-1]);
            
        }
        
        return {minn,maxx};
    }
};