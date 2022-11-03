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
    long dfs(TreeNode* root, int mini){
        if(!root)return LONG_MAX;
        
        if(root->val!=mini){
            return root->val;
        }
        
        return min(dfs(root -> left, mini),dfs(root -> right,mini));
    }
    int findSecondMinimumValue(TreeNode* root) {
        long ans = dfs(root , root -> val);
        if(ans == LONG_MAX){
            return -1;
        }
        return ans;
    }
};