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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            store.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans(store.size(), 0);
        stack<int> st;

        for (int i = store.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= store[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(store[i]);
        }
        
        return ans;
    }
};

