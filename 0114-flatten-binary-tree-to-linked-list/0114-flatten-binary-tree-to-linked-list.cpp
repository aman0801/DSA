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
    void getFlatten(TreeNode* root, vector<TreeNode*> &flattened)
    {
        if(!root) return;
        flattened.push_back(root);
        getFlatten(root->left,flattened);
        getFlatten(root->right,flattened);        
    }
    void flatten(TreeNode* root) {
        if(!root || !root->left && !root->right) return;
        vector<TreeNode*> flattened;
        getFlatten(root,flattened);
        TreeNode* temp=root;
        for(auto x:flattened)
        {
            temp->right=x;
            temp->left=NULL;
            temp=temp->right;
        }
    }
};