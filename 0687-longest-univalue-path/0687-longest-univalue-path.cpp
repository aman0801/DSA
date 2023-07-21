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
    int find(TreeNode* root, int& longest) {
        if (root == nullptr) {
            return 0;
        }
        int lf = find(root->left, longest);
        int rf = find(root->right, longest);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left && root->val == root->left->val) {
            leftPath = lf + 1;
        }

        if (root->right && root->val == root->right->val) {
            rightPath = rf + 1;
        }

        longest = max(longest, leftPath + rightPath);
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int longest = 0;
        find(root, longest);
        return longest;
    }
};