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
        
    int distributeCoins(TreeNode* root, int& ans){
            if(root == NULL){
                    return 0;
            }
            int l = distributeCoins(root->left, ans);
            int r = distributeCoins(root->right, ans);
            ans = ans + abs(l)+abs(r);
            return (l+r+root->val)-1;
    }    
        
    int distributeCoins(TreeNode* root) {
            int ans=0;
            distributeCoins(root, ans);
            return ans;
    }
};