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
    int find(TreeNode* root, int sum){
        if(root == NULL)return 0;
        sum = sum*10+root->val;
         if(!root -> left && !root -> right) return sum;
       return find(root->left, sum)+find(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return find(root, 0);
    }
};