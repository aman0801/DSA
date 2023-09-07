class Solution {
public:
    void insert(ListNode*& head, int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        left--;
        right--;

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }

        ListNode* ans = nullptr;
        for (int i = 0; i < arr.size(); i++) {
            insert(ans, arr[i]);
        }
        return ans;
    }
};