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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int a=maxDepth(root->left);
        int b=maxDepth(root->right);
        
        return 1+max(a,b);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root->left==NULL and root->right==NULL)
            return root->val;
        int lh = maxDepth(root->left);
        int lr = maxDepth(root->right);
        
        if(lr>lh){
            return findBottomLeftValue(root->right);
        }
        return findBottomLeftValue(root->left);
    }
};