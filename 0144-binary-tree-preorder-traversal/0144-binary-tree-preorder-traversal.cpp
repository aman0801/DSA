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
 void helper(TreeNode*root,vector<int>&m1){
        if(!root) 
            return;
         m1.push_back(root->val);
        helper(root->left,m1);
        helper(root->right,m1);
    }
class Solution {
public:
   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>m1;
        helper(root,m1);
        return m1;
    }
};