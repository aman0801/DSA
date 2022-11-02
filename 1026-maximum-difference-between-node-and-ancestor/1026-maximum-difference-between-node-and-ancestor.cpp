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
    int ans = 0;
    void help(TreeNode* root, int mini, int maxi){
         while(!root) 
            return;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        
        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        help(root->left,mini,maxi);
        help(root->right,mini,maxi);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        help(root,root->val,root->val);
        return ans;
    }
};