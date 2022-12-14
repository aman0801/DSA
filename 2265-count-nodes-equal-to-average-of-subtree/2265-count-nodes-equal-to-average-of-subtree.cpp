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
    int avg(TreeNode* root, int &count){
        if(root == NULL)return 0;
        
        count++;
        
        int r = avg(root->right, count);
        int l = avg(root->left, count);
        return (root->val + r + l);
    }
    
    void solve(TreeNode* root){
        if(root == NULL)return;
        int count = 0;
        int sum = (avg(root, count))/count;
        
        if(sum == root->val)ans++;
        
        solve(root->right);
        solve(root->left);
    }
    
    int averageOfSubtree(TreeNode* root) {
         ans = 0;
        solve(root);
        return ans;
    }
};