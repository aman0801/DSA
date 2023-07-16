/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    void solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);

        int maxCount = INT_MIN;
        vector<int> sol;

        for (auto& i : mp) {
            maxCount = max(maxCount, i.second);
        }

        for (auto& i : mp) {
            if (i.second == maxCount) {
                sol.push_back(i.first);
            }
        }

        return sol;
    }
};
