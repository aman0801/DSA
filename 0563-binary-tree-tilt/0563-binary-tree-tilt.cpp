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
    int sum = 0;
    int ans(TreeNode* root){
        if(root == NULL)return 0;
        
        int leftVal = ans(root->left);
        int rightVal = ans(root->right);
        
        int val = abs(leftVal - rightVal);
         sum = sum + val;
        
        return leftVal + rightVal + root -> val;
    }
    int findTilt(TreeNode* root) {
        ans(root);
        return sum;
    }
};