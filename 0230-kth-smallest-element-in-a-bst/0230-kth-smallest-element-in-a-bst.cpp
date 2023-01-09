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
    void treeIter(TreeNode* root, vector<int>& treeVec) {
        if(!root) return;
        treeIter(root->left, treeVec);
        treeVec.push_back(root->val);
        treeIter(root->right, treeVec);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> treeVec;
        treeIter(root, treeVec);
        return treeVec[k-1];
    }
};